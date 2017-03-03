/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/09/09
*Assignment 1, Problem 4:
*A program which prompts the user for a velocity and a time duration and outputs the relative time duration on Earth
*/

import java.util.Scanner;

public class TimeDilation {
	
	public static void main(String [] args) {
		/*This section gets input from the user.  I used the variable names used in the assignment - percentage p and time t in hours:*/
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter a velocity which represents the percentage of the speed of light:");
		double p = s.nextDouble();
		
		System.out.println("Enter a time duration in hours:");
		double t = s.nextDouble();
		
		/*This section calculates the relative time duration on Earth (in hours) and prints that information:*/
		double totalTimeDilation = t/(Math.pow((1-Math.pow(p,2)),.5));
		double timeDilationYears = Math.floor(totalTimeDilation/8766);
		totalTimeDilation = totalTimeDilation-timeDilationYears*8766;
		double timeDilationWeeks = Math.floor(totalTimeDilation/168);
		totalTimeDilation = totalTimeDilation-timeDilationWeeks*168;
		double timeDilationDays = Math.floor(totalTimeDilation/24);
		totalTimeDilation = totalTimeDilation-timeDilationDays*24;
		double timeDilationHours = Math.floor(totalTimeDilation);
		totalTimeDilation = totalTimeDilation-timeDilationHours;
		double timeDilationMinutes = totalTimeDilation*60;
		
		System.out.printf("Your friends on Earth would experience:\n");
		
		if(timeDilationYears>=1) {
			System.out.printf("%.0f year(s)\n", timeDilationYears);
		}
		if(timeDilationWeeks>=1) {
			System.out.printf("%.0f week(s)\n", timeDilationWeeks);
		}
		if(timeDilationDays>=1) {
			System.out.printf("%.0f day(s)\n", timeDilationDays);
		}
		if(timeDilationHours>=1) {
			System.out.printf("%.0f hour(s)\n", timeDilationHours);
		}
		System.out.printf("%.2f minute(s)\n", timeDilationMinutes);
	}
}