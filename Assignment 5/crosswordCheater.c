/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/23/2015
*Assignment 5, Problem 2:
*A program which takes a partial word and produces of possible valid English words by matching them against a standard dictionary 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Function prototypes
int comparator(const char* dictionaryWord, const char* partial, const int size);
void cheat(const char* word);

//A function which compares the partial word to a complete word
int comparator(const char* dictionaryWord, const char* partial, const int size){
    int i;
    for(i=0; i < size; i++){
        if(partial[i] != '-' && dictionaryWord[i] != partial[i]){
             return 0;
        }
    }
	return 1;
}

//The cheater function
void cheat(const char* word){
	
	printf("Searching for words matching %s:\n", word);
	
	FILE * dictionary;
    dictionary = fopen("/usr/share/dict/american", "r");
    char buffer[100];
	int sizeOfWord = strlen(word);
	
	while(fgets(buffer, 100, dictionary)!=NULL){
		//The -1 accounts for the newline character added by fgets
		int sizeOfBuffer = strlen(buffer)-1;
		
		if (sizeOfBuffer == sizeOfWord) {
			if(comparator(buffer, word, sizeOfWord)){
				printf("%s", buffer);
			}
		}
	}
}

//The main function
int main(int argc, char **argv){
    cheat(argv[1]);
    return 0;
}
