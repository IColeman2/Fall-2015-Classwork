/**
 * PhysicsCalc.java
 * Carden Reichert
 * This program computes the force of an object.  The methods need to be
 * implemented.
 * 
 * Adapted from physicsCalc.c by Tony Schneider.
 * CSE 155H Fall 2012
 */
import java.util.Scanner;

public class PhysicsCalc {
    
	public static double getVelocity(double distance, double time) {
		double velocity = distance/time;
		return velocity;
	}

	public static double getAcceleration(double initVelocity, double velocity, double time) {
		double acceleration = (velocity - initVelocity)/time;
		return acceleration;
	}

	public static double getForce(double mass, double acceleration) {
		double force = mass*acceleration;
		return force;
	}
	
    public static void main( String[] args ){
        
        Scanner input = new Scanner( System.in );
        
        
        double distance, time, initVelocity, mass;
        
        System.out.print( "Enter the distance the object traveled: " );
        distance = input.nextDouble();
        System.out.println();
        
        System.out.print( "Enter the time it took to travel that distance: " );
        time = input.nextDouble();
        System.out.println();
        
        System.out.print( "Enter the initial velocity of the object(m/s): " );
        initVelocity = input.nextDouble();
        System.out.println();
        
        System.out.print( "Enter the mass of the object(g): " );
        mass = input.nextDouble();
        System.out.println();
        
        
        /* Invoke your written methods here */
        double velocity = getVelocity(distance, time);
		double acceleration = getAcceleration(initVelocity, velocity, time);
		double force = getForce(mass, acceleration);
        
        /* Print the result here */
        System.out.printf("The velocity of the object is %f m/s, the acceleration of the object is %f m/s^2, and the total force of the object is %f N.\n", velocity, acceleration, force);
		
    }
    
}
