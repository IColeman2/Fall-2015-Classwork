#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	double dollar = 0.0;
	double pounds = 0.0;
	double JPY = 0.0;
	
	printf("Please input the total amount of US dollars:\n");
	scanf("%lf", &dollar);
	
	dollar = dollar - dollar * .1;
	pounds = dollar / 2.0 * .6;
	JPY = dollar / 2.0 * 76.8;
	
	printf("You get %.2f British Pounds and %.2f Japanese Yen.", pounds, JPY);
	
	return 0;
}