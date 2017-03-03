/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/19/2015
*A shitty tester for string_utils
*/

#include "string_utils.c"

int main(int argc, char **argv){
	char *test = scrubHTML("asv&klj<adf>sdfv");
	printf("scrubHTML test: %s\n\n", test);
	
	char *test2 = smartScrubHTML("ampersand:[&]lessthan:[<]greaterthan:[>]escapedAmp:[&amp;]");
	printf("smartScrubHTML test: %s\n\n", test2);
	
	char *test3 = (char *) malloc(sizeof(char) * 34);
	strcpy(test3, "       crawling in my skin       ");
	trim(test3);
	printf("trim test: %s-\n\n", test3);
	
	char *test4 = formatPhoneNumber("+4025551234");
	printf("%d\n", strlen(test4));
	printf("formatPhoneNumber test: %s\n\n", test4);
	
	//int test5 = getFileSize("sansTestFile.txt");
	//printf("getFileSize test: %d\n\n", test5);
	
	char *test6 = getFileContents("sansTestFile.txt");
	printf("getFileContents test: %sEND\n\n", test6);
	
}