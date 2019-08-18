
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
C is pain. I am become pain   
*/

#define BUFFER_LENGTH 100
#define NUM_WORDS 120
#define WORD_LENGTH 21

char* wordlist[NUM_WORDS];
int wordcount = 0;

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
    
	while(fgets(buffer, sizeof(char) * BUFFER_LENGTH, infile) ) { //while !EOF
        buf_ptr = strtok(buffer," ."); //tokenize string by delims
        while(buf_ptr != NULL){        // while !end of buffer
  //          printf("%s\n", buf_ptr);   //print token 
            wordlist[wordcount] = buf_ptr;
            wordcount++;
            buf_ptr = strtok(NULL, " ."); //places a null terminator and tokenizes from that location
        }
        
     
    }
    for(int i = 0; i < 10;i++){
        printf( *(wordlist+i) );
    
    }

        fclose(infile);
	    fclose(outfile);	
	    return 0;

}














	 
