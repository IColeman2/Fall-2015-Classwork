/**
*I Coleman
*icoleman@huskers.unl.edu
*9/29/2015
*Assignment 2, Problem 3:
*A program that takes a list of pairs of numbers then calculates intermediate air distances between each location as well as final total distance
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*So that I only have to write the code once, I intend to use a function to compute air distance:*/
double computeAirDistance(double latA, double latB, double longA, double longB);

/*And another to convert degrees to radians:*/
double degreesToRadians(double deg);

int main(int argc, char **argv) {
	
	/*Error handling*/
	if (argc < 5) {
		printf("ERROR: Enter at least two points.\n");
		exit(1);
	}
	/*"i" is just a generic integer to use for the for loop*/
	int i;
	double totalDistance;
	
	for(i = 1; i<argc-3; i+=2) {
	
	
		double latA = degreesToRadians(atof(argv[i]));
		double longA = degreesToRadians(atof(argv[i+1]));
		double latB = degreesToRadians(atof(argv[i+2]));
		double longB = degreesToRadians(atof(argv[i+3]));
	
		double airDistance = computeAirDistance(latA, latB, longA, longB);
	
		/*Print output:*/
		printf("(%.4f, %.4f) to (%.4f, %.4f): %.4f km\n", atof(argv[i]), atof(argv[i+1]), atof(argv[i+2]), atof(argv[i+3]), airDistance);
		totalDistance+=airDistance;
	}
	
	printf("Total distance: %.4f\n", totalDistance);
	
	return 0;
}

/*Definition of the air distance function*/
double computeAirDistance(double latA, double latB, double longA, double longB) {
	return (acos(sin(latA)*sin(latB)+cos(latA)*cos(latB)*cos(longB-longA))*6371);
}

/*Definition of the degrees-to-radians function*/
double degreesToRadians(double deg) {
	return(deg/180*3.14159);
}