/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/09/09
*Assignment 1, Problem 5:
*A program that prompts the user for the mass of an isotope, its half-life and a number of years and outputs the amount of the isotope remaining after those years
*/


#include<stdlib.h>
#include<stdio.h>
#include<math.h>


int main(int argc, char **argv) {
	/*I will be using the standard abbreviations given in the assignemnt: m for mass, H for half-life, and y for years*/
    double m;
	double y;
	double H;
	
	/*Acquire the necessary inputs:*/
	
	printf("Enter the mass of an isotope (in kilograms):\n");
	scanf("%lf", &m);
	
	printf("Enter the isotope's half-life:\n");
	scanf("%lf", &H);
	
	printf("Enter a length of time in years:\n");
	scanf("%lf", &y);
	
	/*Calculate the amount of the isotope remaining after y years:*/
	
	double amountRemaining = m*pow(0.5, (y/H));
	
	printf("Starting with %lfkg of an isotope with half-life %lf years, after %lf years you would have %lf kilograms left.\n",m,H,y,amountRemaining);
	
	return 0;
	
}