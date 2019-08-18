
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
C is pain. I am become pain   
*/

#define BUFFER_LENGTH 100
#define NUM_WORDS 120
#define WORD_LENGTH 21

char word_list[NUM_WORDS][WORD_LENGTH];
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
    
    char word[WORD_LENGTH];
    char *word_ptr;
    
	while(fgets(buffer, sizeof(char) * BUFFER_LENGTH, infile) ) {
        buf_ptr = buffer;
        if(*buf_ptr != '\x0a'){
            *word_ptr = *buf_ptr;
            word_ptr++;
            buf_ptr++;
        }
        else{
            wordlist[][]
        }    
         
    }
    printf("%c", *buf_ptr);   
    buf_ptr = buf_ptr+2;
    printf( *buf_ptr);   
    


        fclose(infile);
	    fclose(outfile);	
	    return 0;

}














	 
