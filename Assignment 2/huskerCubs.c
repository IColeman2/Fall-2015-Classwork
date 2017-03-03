/**
*I Coleman
*icoleman@huskers.unl.edu
*9/25/2015
*Assignment 2, Problem 1:
*A variation on the "FizzBuzz challenge"
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*Rather than use nesting loops, I intend to use a function to check if a number is prime:*/
int primeCheck(int number);

int main(int argc, char **argv) {
	
	/*Error handling*/
	if (argc != 2) {
		printf("ERROR: Please enter only one argument.\n");
		exit(1);
	}
	
	int n = atoi(argv[1]);
	if (n<1) {
		printf("ERROR: Invalid input.\n");
		exit(0);
	}
	
	int i;
	
	/*1 is always a perfect square, so there's no need to actually test that - we can start the tests at 2*/
	printf("Go Huskers!\n");
	
	for (i=2; i<=n; i++) {
		
		/*Check if the number is prime and print "Go Cubs!" if it is*/
		if(primeCheck(i)==1) {
			printf("Go Cubs!\n");
		}
		
		/*Check if the number is a perfect square and print "Go Huskers!" if it is*/
		else {
			int j = sqrt((double)(i));
			if(j*j==i) {
				printf("Go Huskers!\n");
			}	
			/*Having failed the two previous tests, just print the number*/
			else {
				printf("%d\n", i);
			}
		}
		
	}
	
	return 0;
	
}

/*Definition of the prime checking function*/
int primeCheck(int number) {
    int k;
    for (k=2; k<number; k++) {
        if (number % k == 0 && k != number) return 0;
    }
    return 1;
}
