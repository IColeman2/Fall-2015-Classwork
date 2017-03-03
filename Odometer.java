/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/09/09
*Assignment 1, Problem 2:
*A program to compute the real cost of driving
*/

import java.util.Scanner;

public class Odometer {
	
	public static void main(String [] args) {
		
		/*Get the beginning odometer reading, the ending odometer reading, the number of gallons it took to fill the tank, and the cost of gas:*/
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the beginning odometer reading:");
		double beginningReading = s.nextDouble();
		
		System.out.println("Enter the ending odometer reading:");
		double endingReading = s.nextDouble();
		
		System.out.println("Enter the number of gallons required to fill the tank:");
		double numberOfGallons = s.nextDouble();
		
		System.out.println("Enter the cost of gas in dollars per gallon:");
		double costOfGas = s.nextDouble();
		
		
		/*Calculate the miles driven, the miles per hallon, and the cost per mile*/
		double milesDriven = endingReading-beginningReading;
		double milesPerGallon = milesDriven/numberOfGallons;
		double costPerMile = costOfGas/milesPerGallon;
		
		/*If the values given are not valid, give an error message.  Otherwise, output the relevant data:*/
		
		if(milesDriven < 0) {
			System.out.println("Invalid input (negative mileage)");
		}
		else {
			System.out.printf("Miles driven: %.2f\n", milesDriven);
			System.out.printf("Miles per gallon: %.2f\n", milesPerGallon);
			System.out.printf("Cost per mile: %.2f\n", costPerMile);
		}

		
	}
}