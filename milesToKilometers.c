/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/08/31
*Miles to Kilometers program
*/

#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv) {
	
	printf("Please enter a number of miles: ");
	
	double miles = 0.0;
	
	scanf("%lf", &miles);
	
	double kms = miles * 1.609344;
	
	printf("That is %f kilometers\n", kms);
	
	return 0;
}