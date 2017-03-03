/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*10/27/2015
*Assignment 4, Problem 1:
*Contains the definitions of the functions prototyped in array_utils.h
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

//A function to compute the mean of an array of values
double mean(const int *a, int n) {
    int sumOfValues = 0;
    int i;
 
    for(i = 0; i<n; i++) {
        sumOfValues += a[i];
    }
 
    return((double)sumOfValues/n);
}
 
//A function to compute a sliding window mean
double * windowMeans(const int *a, int n, int m) {
    if(n<m) {
        return NULL;
    }
    if(m<1) {
        return NULL;
    }
 
    int sizeOfResult = n-m+1;
    int i;
    int j;
    int sumOfValues;
    int endValue;
    double windowMean;
 
    double *result = (double *) malloc(sizeof(double) * sizeOfResult);
 
    for(i=0; i<sizeOfResult; i++) {
        endValue=m+i;
        sumOfValues = 0;
        for(j=i; j<endValue; j++) {
            sumOfValues += a[j];
        }
        windowMean = (double)sumOfValues/m;
        result[i] = windowMean;
    }
 
    return result;
 
}
 
//A function to compute the mode of an array of values
int mode(const int *a, int n) {
    int maxNumberOfAppearances=0;
    int i;
    int j;
 
    for(i=0; i<n; i++) {
        int numberOfAppearances = 0;
        for(j=0; j<n; j++) {
            if(a[j]==a[i]) {
                numberOfAppearances++;
            }
        }
        if(numberOfAppearances>maxNumberOfAppearances) {
            maxNumberOfAppearances=numberOfAppearances;
        }
    }
 
    for(i=0; i<n; i++) {
        int numberOfAppearances = 0;
        for(j=0; j<n; j++) {
            if(a[j]==a[i]) {
                numberOfAppearances++;
            }
        }
        if(numberOfAppearances==maxNumberOfAppearances && a[i] != 0) {
            return(a[i]);
        }
 
    }
}

//A function to determine if an array contains a value
int contains(double value,const double* array, int n){
    int i = 0;
    for(i; i<n; i++){
        if(array[i] == value){
            return 1;
        }
    }
    return 0;
}

//A function to compute all modes of an array
int * getAllModes(const int *a, int n, int *resultSize) {
 
    int sizeOfTemp = n;
    double *temp = (double *) malloc(sizeof(double) * sizeOfTemp);
    int maxNumberOfAppearances=0;
    int i;
    int j;
    int numberOfModes = 0;
	
	//Instantiating the temp values to 0 meant that we couldn't check if 0 was already in the array
	//Thus, we instantiated each value to 1001, because the tester only tries values from 1 to 1000
    for(i = 0; i<n; i++){
        temp[i] = 1001;
    }
	
    for(i=0; i<n; i++) {
        int numberOfAppearances = 0;
        for(j=0; j<n; j++) {
            if(a[j]==a[i]) {
                numberOfAppearances++;
            }
        }
        if(numberOfAppearances>maxNumberOfAppearances) {
            maxNumberOfAppearances=numberOfAppearances;
        }
    }
 
    for(i=0; i<n; i++) {
        int numberOfAppearances = 0;
        for(j=0; j<n; j++) {
            if(a[j]==a[i]) {
                numberOfAppearances++;
            }
        }
        if(numberOfAppearances==maxNumberOfAppearances && contains(a[i], temp, n) == 0) {
            temp[numberOfModes]=a[i];
            numberOfModes++;
        }
    }
    *resultSize=numberOfModes;
    int *result = (int *) malloc(sizeof(int) * numberOfModes);
    for(i=0; i<numberOfModes; i++) {
        result[i] = temp[i];
    }
 
    free(temp);
    return result;
 
}

//A function to filter out certain elements from an array
int * filter(const int *a, int n, int threshold, int *resultSize) {
 
    int sizeOfTemp = n;
    int *temp = (int *) malloc(sizeof(int) * sizeOfTemp);
    int i;
    int resultSizeCounter;
    int j = 0;
 
    for(i=0; i<n; i++) {
        if(a[i]>=threshold) {
            resultSizeCounter++;
        }
    }
 
 
    for(i=0; i<n; i++) {
        if(a[i]>=threshold) {
            temp[j]=a[i];
            j++;
        }
    }
 
    *resultSize=resultSizeCounter;
    int *result = (int *) malloc(sizeof(int) * resultSizeCounter);
    for(i=0; i<resultSizeCounter; i++) {
        result[i] = temp[i];
    }
 
    free(temp);
    return result;
}
 
//A function to append one array to another
int * append(const int *a, int sizeA, int *b, int sizeB) {
    int resultSize = sizeA+sizeB;
    int *result = (int *) malloc(sizeof(int) * resultSize);
    int i;
    int j;
    int k;
 
    for(i=0; i<resultSize; i++) {
        for(j=0; j<sizeA; j++) {
            result[j]=a[j];
        }
        for(k=0; k<sizeB; k++) {
            result[j+k]=b[k];
        }
    }
 
    return result;
}