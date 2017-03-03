import java.util.Scanner;

public class milesToKilometers {
	
	public static void main(String [] args) {
		Scanner s = new Scanner(System.in);
		System.out.printf("Please enter a number of miles: ");
	
		double miles = s.nextDouble();
	
		double kms = miles * 1.609344;
	
		System.out.printf("That is %f kilometers\n", kms);
	}
}