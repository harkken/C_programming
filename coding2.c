#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int  magic_number_1[] = {186, 94, 186, 17};
int  magic_number_2[] = {186, 94, 186, 18};

char * wordlist[10];

/*
 * The encode() function may remain unchanged for A#4.
 */


int encode(FILE *input, FILE *output) {
    return 0;
}

int check_magic_num(FILE *input){
	int c;    
    for(int i = 0; i < 4; i++){
        c = fgetc(input);
		// had a typo here where I had magic number2 twice instead of magicnumber1
        if(  (c != magic_number_1[i]) && (c != magic_number_2[i])     ){ 
            printf("Error: File does not contain magic number\n");
			return 1;
        }
     
    }
    return 0;
}
  
int decode(FILE *input, FILE *output) {
	int wordcount = 0;
	int c;
	fpos_t position;
	int lettercount = 0;
	char 
	check_magic_num(input);
	// while there are characters in the file	
	while( ( c = fgetc(input) ) != EOF){
		// if its a letter				
		if( (c > 32 && c < 128) ){
			fgetpos(input, &position);	
			//while it is a word
			while( c > 32 && c < 128){
			lettercount++;
			printf("%c", c);
			c = fgetc(input);
				
			}
			//no longer a word
			wordcount += 1; // update word count
			size_of_array(wordlist);
// IF WORDCOUNT 
			char buffer[lettercount+1]; // Create character buffer
			// determine if we need more space for the word array
			 
			printf("%d", lettercount);
			lettercount = 0;
			printf("\n");
		} 

	
	}
	return 0;   
} 
      
    /*
 		TO DO:
		process numbers for indexing


*/

void size_of_array(char array){
	int n = sizeof(wordlist) / sizeof(char);
	printf("%d", n);

}

void grow_larger_array(){

}




















