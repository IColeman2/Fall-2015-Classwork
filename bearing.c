/**
*I Coleman
*icoleman@huskers.unl.edu
*2015/09/06
*Assignment 1, Problem 3:
*A program that prompts the user for a latitude/longitude of two locations and computes the directional bearing from the origin to the location.
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*Since we will be using PI frequently, let us define a macro to make writing code faster*/
#define PI 3.141596535

int main(int argc, char **argv) {
	
	
	/*Acquire the longitude and latitude of two locations*/
	double latOrigin = 0.0;
	double longOrigin = 0.0;
	double latDestination = 0.0;
	double longDestination = 0.0;
	
	printf("Enter the latitude of your origin:\n");
	
	scanf("%lf", &latOrigin);
	
	printf("Enter the longitude of your origin:\n");
	
	scanf("%lf", &longOrigin);
	
	printf("Enter the latitude of your destination:\n");
	
	scanf("%lf", &latDestination);
	
	printf("Enter the longitude of your destination:\n");
	
	scanf("%lf", &longDestination);
	
	/*Change these values from degrees to radians*/
	
	latOrigin = latOrigin/180*PI;
	longOrigin = longOrigin/180*PI;
	latDestination = latDestination/180*PI;
	longDestination = longDestination/180*PI;
	
	/*Calculate directional bearing*/
	double directionalBearing = atan2(sin(longDestination-longOrigin)*cos(latDestination), cos(latOrigin)*sin(latDestination)-sin(latOrigin)*cos(latDestination)*cos(longDestination-longOrigin));
	if(directionalBearing<0) {
		directionalBearing = directionalBearing+6.2830;
	}
	
	/*Change this value from radians back to degrees, then print the value:*/
	directionalBearing = directionalBearing*180/PI;
	
	printf("Your bearing is %.6f degrees.\n", directionalBearing);
		
	return 0;
	
}