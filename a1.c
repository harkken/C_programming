
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
C is pain. I am become pain   
*/

#define BUFFER_LENGTH 100
#define NUM_WORDS 120
#define WORD_LENGTH 21

char wordlist[NUM_WORDS][20];
int wordcount = 0;
int location = 0;
int flag = 0;
int search( char * word);
void fix_wordlist(void);
void test_for_newline(char * ptr);
void test_flag(FILE* output);
int main(int argc, char *argv[]){
    /*
        PART ONE: FILE I/O
    */
    FILE *infile; // pointer to file being opened
    FILE *outfile; // pointer to file being written to

	char filename[20];	//character array for writing the filename to create the output file name
	
	if(argc < 2){

		fprintf(stderr,"Error: No filename specified. Please enter a filename.\n"); 
		exit(1);
	}

    //this block is used to copy the filename
	infile = fopen(argv[1], "r");	
	strncpy(filename, argv[1], 20 );
    // my issue for a while was writing over the null pointer, classic 
 
	char * fptr;
	fptr = strstr(filename, ".txt");
	strncpy(fptr, ".mtf", 5);
		
	outfile = fopen(filename, "w");
  
    //writing magic number
	fputc(186, outfile);
	fputc(94, outfile);	
	fputc(186, outfile);
	fputc( 17, outfile);
    
    /*
        PART TWO: OBTAIN CHUNKS OF THE PROGRAM FOR PARSING
    */

    char buffer[BUFFER_LENGTH];
    char *buf_ptr; 
   /*
	Document how this function works for future reference.
	note: I was trying to implement some stupid functionality for awhile.
	If you have the lingering feeling that what you're doing is not a good
	approach, then save yourself the pain and find a better way.

	*/
	while(fgets(buffer, sizeof(char) * BUFFER_LENGTH, infile) ) { //while !EOF
        buf_ptr = strtok(buffer," .\n"); //tokenize string by delims
				
        while(buf_ptr != NULL){        // while !end of line?
	//	printf("%s\n", buf_ptr);
		    
           if( search(buf_ptr) == 0 ){ // return 0 means its a unique word and should be copied into the list
                strncpy(wordlist[wordcount], buf_ptr, 20);
                wordcount++;
                fprintf(outfile, "%c", (128+wordcount) );
                fputs(buf_ptr, outfile); 
                
            }
            // we found a match in the existing word list
            else{
				
                fprintf(outfile, "%c", (128+location) );      
            	
        	}
		   
						 
           	buf_ptr = strtok(NULL, " .\n"); //places a null terminator and tokenizes the rest of the line from that location
  
   		
		}
		fputc(10, outfile);
	}
		
		// ------------------FOR LOOP TO PRINT OUT FINAL WORD LIST
		for(int i = 0; i < wordcount;i++){
			printf("%s", wordlist[i]);
		}

	
        fclose(infile);
	    fclose(outfile);	
	    return 0;

	
}
// searches wordlist for current word to avoid duplicates
int search(char* word){
    for(int i = 0; i < wordcount; i++){
        if(strncmp(word, *(wordlist + i), 20) == 0){
            //location = wordcount - i;
			location = wordcount - i - 1;
            fix_wordlist();
            return 1; //word is found
             
        }
    }
    return 0;    
}
// fix_wordlist() more like fix() this function
/*
something is wrong in this general area but i am too tired to fix it right now
*/
void fix_wordlist(){
    char * temp = wordlist[wordcount-location];
    for(int i = (wordcount - location); i < (wordcount);i++){
        strncpy(wordlist[i], wordlist[i], 20); 
    }   
    strncpy(wordlist[wordcount], temp, 20);
	
}
