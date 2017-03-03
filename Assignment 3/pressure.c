#include <stdio.h>
#include <stdlib.h>
#include "pressure.h"

int convertPressure(double *pa, double *psi, double *atm, double *torr, Scale scale){
    if(pa == NULL || psi == NULL || atm == NULL || torr == NULL){
        return NULL_POINTER;
    }
	if(scale==PASCAL){
		if(*pa<0){
			return NEGATIVE_PRESSURE_VALUE;
		}
		else {
			*atm = *pa/101325.0;
			*psi = *pa/6894.75729;
			*torr = *atm*760.0;
			return 0;
		}
	}
	if(scale==PSI){
		if(*psi<0){
			return NEGATIVE_PRESSURE_VALUE;
		}
		else {
			*pa = *psi*6894.75729;
			*atm = *pa/101325.0;
			*torr = *atm*760.0;
			return 0;
		}
	}
	if(scale==ATM){
		if(*atm<0){
			return NEGATIVE_PRESSURE_VALUE;
		}
		else {
			*pa = *atm*101325;
			*psi = *pa/6894.75729;
			*torr = *atm*760.0;
			return 0;
		}
	}
	if(scale==TORR){
		if(*torr<0){
			return NEGATIVE_PRESSURE_VALUE;
		}
		else {
			*atm = *torr/760.0;
			*pa = *atm*101325.0;
			*psi = *pa/6894.75729;
			return 0;
		}
	}
	else{
		return INVALID_SCALE;
	}
}
