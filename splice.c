
#include <stdio.h>
#include <stdlib.h>
#include "pressure.h"

int main(int argc, char **argv){
	int a = {2, 9, 5, 4, 8};
	
	int *array = splice(const int *a, int n, const int *b, int m, int index);
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	} 
}

	//This is the important bit:
	int *splice(const int *a, int n, const int *b, int m, int index) {
		if(n<=0||m<=0) {
			return NULL;
		}
		else if(index<n||index>n) {
			return NULL;
		}
		else {
			int *temp = (int *)malloc(sizeOf(int) * (n+m));
			int sizeOfTemp = n+m;
			
			int i;
			for(i=0; i<n; i++) {
				if(i<index||i>index) {
					temp[sizeOfTemp]= a[i];
					sizeOfTemp ++;
				}
				else if(i==index) {
					int j;
					for (j=0; j<m; j++) {
						temp[sizeOfTemp]= b[j];
						sizeOfTemp ++;
					}
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
	}