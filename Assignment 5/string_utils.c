/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/18/2015
*Assignment 5, Problem 1:
*Contains the definitions of the functions prototyped in string_utils.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string_utils.h"

//A function that replaces special characters in a string with their HTML entities
char * scrubHTML(const char *str) {
	int size = strlen(str);
	int sizeOfTemp = size * 6;
	int resultSizeCounter = 0;
	int i;
	
	char *temp = (char *) malloc(sizeof(char) * sizeOfTemp);
	temp[0]='\0';
	
	for(i = 0; i<size; i++) {
		if(str[i]=='&') {
			strcat(temp, "&amp;");
			resultSizeCounter+=5;
		}
		else if(str[i]=='<') {
			strcat(temp, "&lt;");
			resultSizeCounter+=4;
		}
		else if(str[i]=='>') {
			strcat(temp, "&gt;");
			resultSizeCounter+=4;
		}
		else if(str[i]=='"') {
			strcat(temp, "&quot;");
			resultSizeCounter+=6;
		}
		else {
			temp[resultSizeCounter]=str[i];
			resultSizeCounter++;
			temp[resultSizeCounter]='\0';
		}
	}
	
	char *result = (char *) malloc(sizeof(char) * resultSizeCounter);
	strcpy(result, temp);
	
	free(temp);
	return result;
}

//A version that escapes special characters UNLESS they are already escaped
char * smartScrubHTML(const char *str){
	int size = strlen(str);
	int sizeOfTemp = size * 6;
	int resultSizeCounter = 0;
	int i;
	
	char *temp = (char *) malloc(sizeof(char) * sizeOfTemp);
	temp[0]='\0';
	
	for(i = 0; i<size; i++) {
		if(str[i]=='&') {
			if (isAlreadyEscaped(str, i)==1) {
				temp[resultSizeCounter]=str[i];
				resultSizeCounter++;
				temp[resultSizeCounter]='\0';
			}
			else {
				strcat(temp, "&amp;");
				resultSizeCounter+=5;
			}
		}
		else if(str[i]=='<') {
			strcat(temp, "&lt;");
			resultSizeCounter+=4;
		}
		else if(str[i]=='>') {
			strcat(temp, "&gt;");
			resultSizeCounter+=4;
		}
		else if(str[i]=='"') {
			strcat(temp, "&quot;");
			resultSizeCounter+=6;
		}
		else {
			temp[resultSizeCounter]=str[i];
			resultSizeCounter++;
			temp[resultSizeCounter]='\0';
		}
	}
	
	char *result = (char *) malloc(sizeof(char) * resultSizeCounter);
	strcpy(result, temp);
	
	free(temp);
	return result;
}

//A function (not required by the assignment) that checks if a special character is already escaped for use in smartScrubHTML
int isAlreadyEscaped(const char *str, int i) {
	if(str[i+1]=='a'
	   &&str[i+2]=='m'
	   &&str[i+3]=='p'
	   &&str[i+4]==';') {
		   return 1;
	}
	if(str[i+1]=='l'
	   &&str[i+2]=='t'
	   &&str[i+3]==';') {
		   return 1;
	}
	if(str[i+1]=='g'
	   &&str[i+2]=='t'
	   &&str[i+3]==';') {
		   return 1;
	}
	if(str[i+1]=='q'
	   &&str[i+2]=='u'
	   &&str[i+3]=='o'
	   &&str[i+4]=='t'
	   &&str[i+5]==';') {
		   return 1;
	}
	return 0;
}

//A function that removes leading and trailing whitespace from a string
void trim(char *str) {
	int size = strlen(str);
	int resultSizeCounter = 0;
	
	int i = 0;
	while(isspace(str[i])) {
		i++;
	}

	int j = size-1;
	while(isspace(str[j])) {
		j--;
	}
	
	int tempSize = j - i;
	
	char *temp = (char *) malloc(sizeof(char) * tempSize);
	
	int k;
	for(k=i; k<j+1; k++) {
		temp[resultSizeCounter]=str[k];
		resultSizeCounter++;
	}
	
	temp[resultSizeCounter]='\0';
	
	strcpy(str, temp);
	
	free(temp);
}

//A function that reformats a string representing a telephone number
char * formatPhoneNumber(const char *phone) {
	int size = strlen(phone);
	
	char *result = (char *) malloc(sizeof(char) * 15);
	result[0] = '(';
	
	int i;
	int resultCounter = 1;
	
	for(i=0; i<size; i++) {
		
		if(isdigit(phone[i])) {
			result[resultCounter]=phone[i];
			
			resultCounter++;
			
			if(resultCounter==4) {
				result[resultCounter] = ')';
				resultCounter++;
				result[resultCounter] = ' ';
				resultCounter++;
			}
			if(resultCounter==9) {
				result[resultCounter] = '-';
				resultCounter++;   
			}
		}
	}
	result[resultCounter] = '\0';
	return result;
}

//A function to compute the size of a file in bytes:
int getFileSize(const char *fileName) {
	FILE *file = fopen(fileName, "r");
	
	int fileSize = 0;
	while(fgetc(file)!=EOF) {
		fileSize++;
	}
	
	fclose(file);
	
	return fileSize;
}

//A function to retrieve the contents of a file given the file name as a string
char * getFileContents(const char *fileName){
	FILE *file = fopen(fileName, "r");
	
	int size = getFileSize(fileName)+1;
	char *result = (char *) malloc(sizeof(char) * size);
	
	int i;
	for(i=0; i<size; i++) {
		result[i]=fgetc(file);
	}
	result[size-1]='\0';
	fclose(file);
	return result;
}