/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/18/2015
*Assignment 5, Problem 1:
*Several functions that operate on strings
*/

//A function that replaces special characters in a string with their HTML entities
char * scrubHTML(const char *str);

//A version that escapes special characters UNLESS they are already escaped
char * smartScrubHTML(const char *str);

//A function (not required by the assignment) that checks if a special character is already escaped for use in smartScrubHTML
int isAlreadyEscaped(const char *str, int i);

//A function that removes leading and trailing whitespace from a string
void trim(char *str);

//A function that reformats a string representing a telephone number
char * formatPhoneNumber(const char *phone);

//A function to compute the size of a file in bytes:
int getFileSize(const char *fileName);

//A function to retrieve the contents of a file given the file name as a string
char * getFileContents(const char *fileName);