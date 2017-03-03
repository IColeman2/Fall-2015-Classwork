/**
*I Coleman
*icoleman@huskers.unl.edu
*9/30/2015
*Assignment 2, Problem 4:
*A program that finds all subsequences of a given DNA string of length n with the maximal frequency of C and G in it
*/

import java.util.Scanner;

public class CGIslands {
	
	public static void main(String [] args) {
		
		/*"n" is the variable name given in the assignment:*/
		int n=Integer.parseInt(args[0]);
		System.out.printf("n = %d\n", n);
		
		char[] dnaStrand = args[1].toCharArray();
		int maxNumberOfCGs = 0;
		
		for(int i=0; i<=dnaStrand.length; i++) {
			int numberOfCGs = 0;
			for(int j=i; j<i+n&&j<dnaStrand.length; j++) {
				if(dnaStrand[j]=='C'||dnaStrand[j]=='G') {
					numberOfCGs+=1;
				}
			}
			if(numberOfCGs>maxNumberOfCGs) {
				maxNumberOfCGs=numberOfCGs;
			}
		}
		double highestFrequency = (double)(maxNumberOfCGs)/n*100;
		System.out.printf("highest frequency: %d / %d = %.2f%%\n", maxNumberOfCGs, n, highestFrequency);
		System.out.println("CG Islands:");
		
		for(int i=0; i<=dnaStrand.length; i++) {
			int numberOfCGs = 0;
			for(int j=i; j<i+n&&j<dnaStrand.length; j++) {
				if(dnaStrand[j]=='C'||dnaStrand[j]=='G') {
					numberOfCGs+=1;
				}
			}
			if(numberOfCGs==maxNumberOfCGs) {
				System.out.printf("%d thru %d: %s\n", i, i+n, args[1].substring(i, i+n));
			}
		}
	}
}