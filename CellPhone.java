/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/09/09
*Assignment 1, Problem 6:
*A program to help people track their cell phone usage.
*/

import java.util.Scanner;

public class CellPhone {
	
	public static void main(String [] args) {
		
		/*Get the number of minutes in the plan per 30 day period, the current day in the 30 day period, and the total number of minutes used so far:*/
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number of minutes in the plan per 30 day period:");
		int m = s.nextInt();
		
		System.out.println("Enter the current day in the 30 day period:");
		int d = s.nextInt();
		
		System.out.println("Enter the total number of minutes used so far:");
		double u = s.nextDouble();
		
		/*Calculate days remaining, average daily use, and the useable minutes which remain:*/
		int daysRemaining = 30-d;
		double actualAvgDailyUse = u/d;
		double avgDailyUse = m/30;
		double useableMinutes = (m-u)/(daysRemaining);
		
		/*Determine if the user is over or under average daily use and print results:*/
		System.out.printf("%d days used, %d days remaining.\n", d, daysRemaining);
		System.out.printf("Average use: %.0f minutes per day.\n", actualAvgDailyUse);
		
		if(actualAvgDailyUse>avgDailyUse) {
			double projectedUse = actualAvgDailyUse*30-m;
			System.out.printf("You are EXCEEDING your average daily use (%.2f min/day).  Continuing this high usage, you'll exceed your minute plan by %.2f minutes.\n", avgDailyUse, projectedUse);
			System.out.printf("To stay below your minute plan, use no more than %.0f minutes per day.\n", useableMinutes);
		}
		else if(actualAvgDailyUse<avgDailyUse) {
			System.out.printf("You are UNDER your average daily use (%.2f min/day).\n", avgDailyUse);
			System.out.printf("You can safely use %.0f minutes per day and still stay within your minute plan.\n", useableMinutes);
		}
		else {
			System.out.printf("You are meeting your average daily use (%.2f min/day). Keep up the good work!\n", avgDailyUse);
		}
		
	}
}