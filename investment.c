/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/09/06
*Assignment 1, Problem 1:
*A program that prompts the user to enter the cost and gain from an investment and computes and outputs the ROI
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char **argv) {
	
	/*Acquire the cost of investment and declare it as a double-type variable*/
	printf("Enter the cost of your investment:\n");
	
	double costOfInvestment = 0.0;
	
	scanf("%lf", &costOfInvestment);
	
	/*Acquire the gain of investment and declare it as a double-type variable*/
	printf("Enter the gain from your investment:\n");
	
	double gainOfInvestment = 0.0;
	
	scanf("%lf", &gainOfInvestment);
	
	/*Calculate and print the return on investment:*/
	
	double returnOnInvestment = (gainOfInvestment - costOfInvestment)/costOfInvestment*100;
	
	printf("The return on your investment is %1.2f%%.\n", returnOnInvestment);
	
	return 0;
	
}