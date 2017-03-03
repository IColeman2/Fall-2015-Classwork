/**
*I Coleman
*icoleman@huskers.unl.edu
*9/29/2015
*Assignment 2, Problem 5:
*A program that will assist people in saving for retirement using a tax-deferred 401k program
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
	
	/*Error handling:*/
	if (argc != 6) {
		printf("ERROR: Wrong number of arguments.\n");
		exit(0);
	}
	
	/*Getting input and defining variables:*/
	double balance = atof(argv[1]);
	double monthlyContribution = atof(argv[2]);
	if ((monthlyContribution*12) > 17500) {
		printf("ERROR: As of 2014, annual 401k contributions cannot exceed $17500.\n");
		exit(0);
	}
	
	
	double rateOfReturn = atof(argv[3]);
	double inflationRate = atof(argv[4]);
	double inflationAdjustedROR=((1+rateOfReturn)/(1+inflationRate)-1)/12;
	
	int yearsUntilRetirement = atoi(argv[5]);
	int monthsUntilRetirement = yearsUntilRetirement*12;
	
	int month;
	double totalInterest;
	
	printf("Month    Interest     Balance\n");
	for (month=1; month<=monthsUntilRetirement; month++) {
		double interest = inflationAdjustedROR*balance;
		balance = balance + monthlyContribution + interest;
		printf("%5d $ %10.2f $ %10.2f\n", month, interest, balance);
		
		totalInterest += interest;
		
		if(month==monthsUntilRetirement) {
			printf("Total Interest Earned: $ %.2f\n", totalInterest);
			printf("Total Nest Egg: $ %.2f\n", balance);	
		}
	}
	
	return(0);
}

