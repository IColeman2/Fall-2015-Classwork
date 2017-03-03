/**
*I Coleman
*icoleman@huskers.unl.edu
*9/29/2015
*Assignment 2, Problem 2:
*A program that takes an integer n and a subsequent list of integers as command line arguments and determines which number(s) between 1 and n are missing from the list
*/

import java.util.Scanner;

public class Missing {
	
	public static void main(String [] args) {
		
		boolean presentInList=false;
		/*"n" is the variable name given in the assignment:*/
		int n=Integer.parseInt(args[0]);
		
		System.out.printf("Missing numbers 1 thru %d:\n",n);
		/*A for loop that runs through each integer in the specified range*/
		for(int i=1; i<=n; i++) {
			
			/*A for loop that checks for each integer in the given list of arguments*/
			for(int j=1; j<args.length; j++) {
				if (Integer.parseInt(args[j])==i) {
					presentInList=true;
				}
			}
			/*If the integer is missing, print it*/
			if (!presentInList) {
				System.out.printf("%d\n", i);	
			}
			/*Reset the boolean variable so that we can run the for loops again*/
			presentInList=false;
		} 
		
	}
}