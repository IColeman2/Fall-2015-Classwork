#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

//We made max and min functions that find the maximum and minimum of three values
//These were not functions required for the assignment, but they were useful for the toGrayScale function
//math.h's "fmax" and "fmin" functions can only be used for two values
double max(double a, double b, double c){
    if(a>b && a>=c){
        return a;
    }
    else if(b>=a && b>c){
        return b;
    }
    else{
        return c;
    }
}

double min(double a, double b, double c){
    if(a<b && a<=c){
        return a;
    }
    else if(b<=a && b<c){
        return b;
    }
    else{
        return c;
    }
}

//a function to convert degrees to radians
int degreesToRadians(double degree, double *radians) {
	if(radians==NULL) {
		return 1;
	}
	else if(degree<0||degree>360) {
		return 1;
	}
	else {
		*radians=(degree*M_PI/180);
		return 0;
	}
}

//a function to compute the annual percentage yield given an annual percentage rate
int annualPercentageYield(double apr, double *apy) {
	if(apy==NULL) {
		return 1;
	}
	else if(apr<0||apr>1) {
		return 1;
	}
	else {
		*apy=(pow(M_E, apr)-1);
		return 0;
	}
}

//a function to compute the air distance between two locations given their latitude and longitude
int getAirDistance(double latA, double longA, double latB, double longB, double *distance) {
	if(distance==NULL) {
		return 1;
	}
	else if(latA<-180||latA>180||longA<-180||longA>180||
			latB<-180||latB>180||longB<-180||longB>180){
		return 1;
	}
	else {
		
		//degreesToRadians doesn't accept negative values:
		if(latA<0) {
			latA+=360;
		}
		if(longA<0) {
			longA+=360;
		}
		if(latB<0) {
			latB+=360;
		}
		if(longB<0) {
			longB+=360;
		}
		
		double latRadiansA, latRadiansB, longRadiansA, longRadiansB;
		degreesToRadians(latA, &latRadiansA);
		degreesToRadians(latB, &latRadiansB);
		degreesToRadians(longA, &longRadiansA);
		degreesToRadians(longB, &longRadiansB);
		*distance = acos(sin(latRadiansA)*sin(latRadiansB)+cos(latRadiansA)*cos(latRadiansB)*cos(longRadiansB-longRadiansA))*6371;
		return 0;
	}
}

//a function to convert from an RGB color model to a CMYK model
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
	if(c==NULL||m==NULL||y==NULL||k==NULL) {
		return 1;
	}
	else if(r<0||r>255||g<0||g>255||b<0||b>255){
		return 1;
	}
	else{
		double R = r/255.00;
		double G = g/255.00;
		double B = b/255.00;
		*k = 1.00-max(R, G, B);
		*c = (1.00-R-*k)/(1.00-*k);
		*m = (1.00-G-*k)/(1.00-*k);
		*y = (1.00-B-*k)/(1.00-*k);
		return 0;
	}
}

//a function to convert from CMYK to RGB
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
	if(r==NULL||g==NULL||b==NULL) {
		return 1;
	}
	else if(c<0||c>1||m<0||m>1||y<0||y>1||k<0||k>1){
		return 1;
	}
	else{
		*r = (int)((255.00*(1.00-c)*(1.00-k))+.5);
		*g = (int)((255.00*(1.00-m)*(1.00-k))+.5);
		*b = (int)((255.00*(1.00-y)*(1.00-k))+.5);
		return 0;
	}
}

//a function that takes an RGB color value and transforms it to a grayscale version
int toGrayScale(int *r, int *g, int *b, Mode m) {
	if(r==NULL||g==NULL||b==NULL) {
		return 1;
	}
	else if(*r<0||*r>255||*g<0||*g>255||*b<0||*b>255){
		return 1;
	}
	else if(m<0||m>2) {
		return 1;
	}
	else{
		if(m == AVERAGE){
			int value = (int)(((*r+*g+*b)/3.0)+.5);
			*r = value;
			*g = value;
			*b = value;
		}
		if(m == LIGHTNESS){
			int value = (int)(((max((double)*r, (double)*g,(double)*b) + min((double)*r, (double)*g, (double)*b))/2.0)+.5);
			*r = value;
			*g = value;
			*b = value;
		}
		if(m == LUMINOSITY){
			int value = (int)((.21* *r+.72* *g+.07* *b)+.5);
			*r = value;
			*g = value;
			*b = value;
		}
    return 0;
	}
}

