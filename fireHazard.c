#include <stdio.h>
#include <stdlib.h>
#include "fireHazard.h"

typedef enum {OFF, ON} status;

status ** createGrid(int size) {
	status** grid = malloc(sizeof(status*) *size);
	int i;
	int j;
	for(i = 0; i<size; i++) {
		grid[i] = malloc(sizeof(status) *size);
		int i;
		int j;
		for(i=0; i<size; i++) {
			grid[i] = malloc(sizeof(status)*size);
			for(j=0; j<size; j++) {
				grid[i][j] = OFF;
			}
	}
	return grid;
}

void turnOn(status** grid, int x1, int y1, int x2, int y2) {
	int i;
	int j;
	for(i=x1; i<=x2; i++) {
		for(j=y1; j<=y2; j++) {
			grid[i][j] = ON;
		}
	}
}