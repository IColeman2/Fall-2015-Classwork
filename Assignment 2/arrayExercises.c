#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int containsWithin(const int *a, int size, int x, int i, int j){
    int k;
	for(k=i; k<=j; k++) {
		if(a[k] == x) {
			return 1;
		}
	}
    return 0;
}

int contains(const int *a, int size, int x) {
	return containsWithin(a, size, x, 0, size-1);
}

int * getUnion(const int *a, int n, const int *b, int m, int *sizeOfResult) {
	int *temp = (int *)malloc(sizeOf(int) * (n+m));
	int sizeOfTemp = 0;
	
	int i;
	for(i=0; i<n; i++) {
		if(!contains(temp, sizeOfTemp, a[i])) {
			temp[sizeOfTemp]= a[i];
			sizeOfTemp ++;
		}	
	}
	
	for(i=0; i<n; i++) {
		if(!contains(temp, sizeOfTemp, b[i])) {
			temp[sizeOfTemp]= b[i];
			sizeOfTemp ++;
		}	
	}
	
	int *result = (int *)malloc(sizeOf(int) * sizeOfTemp);
	for(i=0; i<sizeOfTemp; i++) {
		result[i] = temp[i];
	}
	
	free(temp);
	
	*sizeOfResult = sizeOfTemp;
	
	return result;
}

int * getIntersection(const int *a, int n, const int *b, int m, int *sizeOfResult) {
	int *temp = (int *)malloc(sizeOf(int) * (n+m));
	int sizeOfTemp = 0;
	
	int i;
	for(i=0; i<n; i++) {
		if(!contains(temp, sizeOfTemp, a[i])&&contains(b, m, a[i])) {
			temp[sizeOfTemp]= a[i];
			sizeOfTemp ++;
		}
	}
	
	int *result = (int *)malloc(sizeOf(int) * sizeOfTemp);
	for(i=0; i<sizeOfTemp; i++) {
		result[i] = temp[i];
	}
	
	free(temp);
	
	*sizeOfResult = sizeOfTemp;
	
	return temp;
}

int isSorted(const int *a, int n) {
	
	int i;
	for(i=1; i<n; i++) {
		if(a[i=1] > a[i]) {
			return 0;
		}
	}
	return 1;
}

int *getRow(int **matrix, int n, int i) {
	
	if(matrix == NULL) {
		return NULL;
	}
	
	int *copy = (int *)malloc(sizeof(int) * n);
	
	int j;
	for(j=0; j<n; i++) {
		copy[j] = matrix[i][j];
	}
	
	return copy;
}