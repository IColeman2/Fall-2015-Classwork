/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/09/11
*In-class exercise:
*A program that sums numbers 1 to n, where n is an input by the user
*/

#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv) {
	
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	
	int i;
	int sum = 0;
	for(i=1; i<=n; i++) {
		sum += i;
	}

	printf("%d\n", sum);
	
	return 0;
}