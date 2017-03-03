/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*10/14/2015
*Assignment 3, Problem 2:
*A demonstration program that prompts the use for one of the scales and a value to convert and outputs the result of all four scales
*/

#include <stdio.h>
#include <stdlib.h>
#include "pressure.h"

int main(int argc, char **argv){
    int scale, error;
    double pascals, psi, torr, atm;
    printf("Please input the desired scale: 1 for pascals, 2 for psi, 3 for atm, 4 for torr\n");
    scanf("%d", &scale);
	
    if(scale == 1){
        printf("Please input pascals\n");
        scanf("%lf", &pascals);
        error = convertPressure(&pascals, &psi, &atm, &torr, PASCAL);
        if(error == NEGATIVE_PRESSURE_VALUE){
            printf("NEGATIVE PRESSURE VALUE ERROR\n");
        }
        if(error == NULL_POINTER){
			printf("NULL POINTER ERROR\n");
        }
        if(error == INVALID_SCALE){
            printf("INVALID SCALE ERROR\n");
        }
        else{
			printf("Pascals: %f\nPSI: %f\nATM: %f\nTorr: %f\n", pascals, psi, atm, torr);
		}
    }
	
    else if(scale == 2){
        printf("Please input psi\n");
        scanf("%lf", &psi);
        error = convertPressure(&pascals, &psi, &atm, &torr, PSI);
        if(error == NEGATIVE_PRESSURE_VALUE){
            printf("NEGATIVE PRESSURE VALUE ERROR\n");
        }
        if(error == NULL_POINTER){
			printf("NULL POINTER ERROR\n");
        }
        if(error == INVALID_SCALE){
            printf("INVALID SCALE ERROR\n");
        }
        else{
			printf("Pascals: %f\nPSI: %f\nATM: %f\nTorr: %f\n", pascals, psi, atm, torr);
		}
    }
	
    else if(scale == 3){
        printf("Please input atmospheres\n");
        scanf("%lf", &atm);
        error = convertPressure(&pascals, &psi, &atm, &torr, ATM);
        if(error == NEGATIVE_PRESSURE_VALUE){
            printf("NEGATIVE PRESSURE VALUE ERROR\n");
        }
        if(error == NULL_POINTER){
			printf("NULL POINTER ERROR\n");
        }
        if(error == INVALID_SCALE){
            printf("INVALID SCALE ERROR\n");
        }
        else{
			printf("Pascals: %f\nPSI: %f\nATM: %f\nTorr: %f\n", pascals, psi, atm, torr);
		}
    }
	
    else if(scale == 4){
        printf("Please input torr:\n");
        scanf("%lf", &torr);
        error = convertPressure(&pascals, &psi, &atm, &torr, TORR);
        if(error == NEGATIVE_PRESSURE_VALUE){
            printf("NEGATIVE PRESSURE VALUE ERROR\n");
        }
        if(error == NULL_POINTER){
			printf("NULL POINTER ERROR\n");
        }
        if(error == INVALID_SCALE){
            printf("INVALID SCALE ERROR\n");
        }
        else{
			printf("Pascals: %f\nPSI: %f\nATM: %f\nTorr: %f\n", pascals, psi, atm, torr);
		}
    }
    else{
        printf("INVALID SCALE ERROR\n");
		return(INVALID_SCALE);
    }
    return 0;
}
