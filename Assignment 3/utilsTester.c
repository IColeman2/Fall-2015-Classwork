/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*10/14/2015
*Assignment 3, Problem 1:
*A test driver program that demonstrates 3 test calls to each of the functions designed in utils.c and utils.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
 
int main(int argc, char **argv){
	
	//declaring variables
    double radians, apy, distance, cyan, magenta, yellow, key;
    int red, green, blue;
    int error;
	Mode mode;
 
	//3 degreesToRadians tests:
    error = degreesToRadians(180, &radians);
    printf("degreesToRadians trial 1: \nInputs: %d\nRadians: %.2f, error code: %d\n",180, radians, error);
 
    error = degreesToRadians(360, &radians);
    printf("degreesToRadians trial 1: \nInputs: %d\nRadians: %.2f, error code: %d\n",360, radians, error);
 
    error = degreesToRadians(0, &radians);
    printf("degreesToRadians trial 1: \nInputs: %d\nRadians: %.2f, error code: %d\n",0, radians, error);
 
    printf("\n");
 
	//3 getAirDistance tests:
    error = getAirDistance( 0,0, 180, 180, &distance);
    printf("getAirDistance trial 1:\nInputs: %d, %d, %d, %d \nDistance: %.2f km, error code: %d\n", 0, 0, 180, 180, distance, error);
    error = getAirDistance( 0, 0, 0, 0, &distance);
    printf("getAirDistance trial 2:\nInputs: %d, %d, %d, %d \nDistance: %.2f km, error code: %d\n", 0, 0, 0, 0, distance, error);
    error = getAirDistance( 75 , 100, 76, 101, &distance);
    printf("getAirDistance trial 3:\nInputs: %d, %d, %d, %d \nDistance: %.2f km, error code: %d\n", 75 , 100, 76, 101, distance, error);
 
	//3 annualPercentageYield tests:
    printf("\n");
    error = annualPercentageYield(1, &apy);
    printf("annualPercentageYield trial 1:\nInputs: %.2f \nAPY: %.2f, error code: %d\n", 1, apy, error);
    error = annualPercentageYield(0, &apy);
    printf("annualPercentageYield trial 2:\nInputs: %.2f \nAPY: %.2f, error code: %d\n", 0, apy, error);
    error = annualPercentageYield(.5, &apy);
    printf("annualPercentageYield trial 3:\nInputs: %.2f \nAPY: %.2f, error code: %d\n", .5, apy, error);
 
	//3 rgbToCMYK tests:
    printf("\n");
    error = rgbToCMYK(1, 255, 160, &cyan, &magenta, &yellow, &key);
    printf("rgbToCMYK trial 1: \nInputs: %d, %d, %d\nCyan: %.4f, Magenta: %.4f, Yellow: %.4f, Key: %.4f error code: %d\n", 1, 255, 160, cyan, magenta, yellow, key, error);
    error = rgbToCMYK(50, 25, 10, &cyan, &magenta, &yellow, &key);
    printf("rgbToCMYK trial 2: \nInputs: %d, %d, %d\nCyan: %.4f, Magenta: %.4f, Yellow: %.4f, Key: %.4f error code: %d\n", 50, 25, 10, cyan, magenta, yellow, key, error);
    error = rgbToCMYK(255, 150, 60, &cyan, &magenta, &yellow, &key);
    printf("rgbToCMYK trial 3: \nInputs: %d, %d, %d\nCyan: %.4f, Magenta: %.4f, Yellow: %.4f, Key: %.4f error code: %d\n", 255, 150, 60, cyan, magenta, yellow, key, error);
    printf("\n");
	
	//3 cmykToRGB tests:
    error = cmykToRGB(.9, .5, .01, .1, &red, &green, &blue);
    printf("cmykToRGB trial 1: \nInputs: %.2f, %.2f, %.2f, %.2f \nRed: %d, Green: %d, Blue: %d error code: %d\n", .9, .5, .01, .1, red, green, blue, error);
    error = cmykToRGB(0, 1, 0, 1, &red, &green, &blue);
    printf("cmykToRGB trial 2: \nInputs: %.2f, %.2f, %.2f, %.2f \nRed: %d, Green: %d, Blue: %d error code: %d\n", .9, .5, .01, .1, red, green, blue, error);
    error = cmykToRGB(0, 0, 0, 0, &red, &green, &blue);
    printf("cmykToRGB trial 3: \nInputs: %.2f, %.2f, %.2f, %.2f \nRed: %d, Green: %d, Blue: %d error code: %d\n", .9, .5, .01, .1, red, green, blue, error);
    printf("\n");
	
	//3 toGrayScale tests:
	printf("\n");
	error = toGrayScale(&red, &green, &blue, AVERAGE);
	printf("toGrayScale trial 1: \nInputs: %.2f, %.2f, %.2f, %.2f \nRed: %d, Green: %d, Blue: %d, Mode: AVERAGE error code: %d\n", red, green, blue, error);
    error = toGrayScale(&red, &green, &blue, LIGHTNESS);
    printf("toGrayScale trial 2: \nInputs: %.2f, %.2f, %.2f, %.2f \nRed: %d, Green: %d, Blue: %d, Mode: LIGHTNESS error code: %d\n", red, green, blue, error);
    error = toGrayScale(&red, &green, &blue, LUMINOSITY);
    printf("toGrayScale trial 3: \nInputs: %.2f, %.2f, %.2f, %.2f \nRed: %d, Green: %d, Blue: %d, Mode: LUMINOSITY error code: %d\n", red, green, blue, error);
    printf("\n");
 
    return 0;
}