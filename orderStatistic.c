/**
 *
 * ithOrder.c
 * This program finds the ith order statistic of
 * a list of numbers passed on the command line.
 *
 * It uses insertion sort (a sorting algorithm) to
 * sort the list then finds i-th order elements in the
 * array.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * This function takes an array of strings and converts
 * them to an array of integers
 */
int * strToIntArray(char **strings, int numStrings);

/**
 * This function sorts an array of integers using
 * the insertion sort algorithm.
 */
void insertionSort(int *arr, int n);

/**
 * This function returns the i-th (i) order statistic of 
 * the given integer array (arr) which has n elements
 */
int getOrderStatistic(int *arr, int n, int i);

int main(int argc, char **argv)
{
  if (argc < 3) {
    printf("Usage: %s <ith order value> <list of unique numbers>\n", argv[0]);
    exit(1);
  }

  int ithOrder = atoi(argv[1]);
  int numElements = argc - 2; 

  if( ithOrder < 1 || ithOrder > numElements) {
    printf("The ith order value must be between 1 and %d\n", numElements);
    exit(-1);
  }

  int *numbers = strToIntArray(&argv[2], numElements);

  int ithElement = getOrderStatistic(numbers, numElements, ithOrder);

  printf("The %dth element is: %d\n", ithOrder, ithElement);

  return 0;
}

void insertionSort(int *array, int size) {
  int value;
  int i;
  for(i=1; i<size; i++) {
    value = array[i];
    int j = i;
    while(j > 0 && array[j-1] > value) {
      array[j] = array[j-1];
      j--;
    }
    array[j] = value;
  }
}

int * strToIntArray(char **strings, int numStrings) {
  int *result = (int *) malloc(sizeof(int) * numStrings);
  int i;
  for(i=0; i<numStrings; i++) {
    result[i] = atoi(strings[i]);
  }
  return result;
}

int getOrderStatistic(int *arr, int n, int i) {
  insertionSort(arr, n); 
  return arr[i-1];
}
