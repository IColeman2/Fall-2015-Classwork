/* Created by Tony Schneider on 1/29/2012
 * Last Modified by Tony Schneider on 1/29/2012
 *
 * physicsCalc.c
 * Used to determine the force of an object.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
//TODO: place your function prototypes here
double getVelocity(double distance, double time);
double getAcceleration(double initVelocity, double velocity, double time);
double getForce(double mass, double acceleration); 
 
int main(int argc, char **argv)
{
    double distance, time, initVelocity, mass;

    printf("Enter the distance the object travled(m): ");
    scanf("%lf", &distance);
    
    printf("Enter the time it took to travel that distance(s): ");
    scanf("%lf", &time);

    printf("Enter the initial velocity of the object(m/s): ");
    scanf("%lf", &initVelocity);

    printf("Enter the mass of the object(g): ");
    scanf("%lf", &mass);

    //TODO: call your functions here
	double velocity = getVelocity(distance, time);
	double acceleration = getAcceleration(initVelocity, velocity, time);
	double force = getForce(mass, acceleration);
	
    //TODO: Print the results here
	printf("The velocity of the object is %lf m/s, the acceleration of the object is %lf m/s^2, and the total force of the object is %lf N.\n", velocity, acceleration, force);
	
    return 0;
}

//TODO: place your function definitions here
double getVelocity(double distance, double time) {
	double velocity = distance/time;
	return velocity;
}

double getAcceleration(double initVelocity, double velocity, double time) {
	double acceleration = (velocity - initVelocity)/time;
	return acceleration;
}

double getForce(double mass, double acceleration) {
	double force = mass*acceleration;
	return force;
}