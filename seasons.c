/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/09/04
*A program to determine the season given a month
*/

#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv) {
	
	printf("Please enter the current month (1-12):\n");
	
	int month;
	
	scanf("%df", &month);
	
	if(month == 3 || month == 4 || month == 5) {
		printf("It is Spring!\n");
	}
	else if(month == 6 || month == 7 || month == 8) {
		printf("It is Summer!\n");
	}
	else if(month == 9 || month == 10 || month == 11) {
		printf("It is Fall!\n");
	}
	else if(month == 12 || month == 1 || month == 2) {
		printf("It is Winter!\n");
	}
	else {
		printf("You got a bad month!");
	}
	
	return 0;
}