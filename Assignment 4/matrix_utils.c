/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*10/27/2015
*Assignment 4, Problem 2:
*A suite of matrix utilities
*/

#include <stdlib.h>
#include <stdio.h>
#include "matrix_utils.h"

//A function that creates a (square) identity matrix of size nxn
int **getIdentityMatrix(int n){
    int i, o;
    int **outerMatrix = malloc(sizeof(int*) * n);
    for(i=0; i<n; i++){
        outerMatrix[i] = malloc(sizeof(int) * n);
    }
    for(i=0; i<n; i++){
        for(o=0; o<n; o++){
            if(i==o){
                outerMatrix[i][o] = 1;
            }
            else{
                outerMatrix[i][o] = 0;
            }
        }
    }
    return outerMatrix;
}

//A function to determine if a given matrix is a permutation matrix
int isPermutationMatrix(int **m, int n){
    int i, o, countH, countV;
    for(i=0; i<n; i++){
        countH = 0;
        countV = 0;
        for(o=0; o<n; o++){
            if(m[i][o] == 1 || m[i][o] == 0 || m[o][i] == 1 || m[o][i] == 0){
                if(m[i][o] == 1){
                    countH++;
                }
                if(m[o][i] == 1){
                    countV++;
                }
            }else{
                return 0;
            }
        }
        if(countV != 1 || countH != 1){
            return 0;
        }
    }
    return 1;
}

//A  function  to  determine  if  a  given  square  matrix  is symmetric
int isSymmetric(int **m, int n){
    int i, o;
    for(i=0; i<n; i++){
        for(o=0; o<n; o++){
            if(m[i][o] != m[o][i]){
                return 0;
            }
        }
    }
    return 1;
}

//A function to compute the trace of a matrix
int trace(int **m, int n){
    int i, o;
    int trace = 0;
    for(i=0; i<n; i++){
        for(o=0; o<n; o++){
            if(i == o){
                trace = trace + m[i][o];
            }
        }
    }
    return trace;
}

//A funtion to flip a matrix along the diagonal, or transpose it
void transpose(int **m, int n){
    int i, o, placeholder;
    for(i=0; i<n; i++){
        for(o=0; o<i; o++){
            placeholder = m[i][o];
            m[i][o] = m[o][i];
            m[o][i] = placeholder;
        }
    }
}

//A function which creates a copy of a matrix, used in transposeCopy and matrixCopy
int ** mcopy(int**m, int n){
    int i, o;
    int **mCopy = malloc(sizeof(int*) * n);
    for(i=0; i<n; i++){
        for(o=0; o<n; o++){
            mCopy[i] = malloc(sizeof(int) * n);
        }
    }
    for(i=0; i<n; i++){
        for(o=0; o<n; o++){
            mCopy[i][o] = m[i][o];
        }
    }
    return mCopy;
}

//A function to transpose a matrix and create a new matrix representing the transpose
int ** transposeCopy(int **m, int n){
    int i, o;
    int **aCopy = mcopy(m, n);
    transpose(aCopy, n);
    return aCopy;
}

//A function to resize a matrix
int ** matrixCopy(int **A, int n, int m, int p, int q){
    int i, o;
    int **mCopy = malloc(sizeof(int*) * p);
    for(i=0; i<p; i++){
        mCopy[i] = malloc(sizeof(int) * q);
    }
    for(i=0; i<p; i++){
        for(o=0; o<q; o++){
            if(i>=n || o>=m){
                mCopy[i][o] = 0;
            }
            else{
                mCopy[i][o] = A[i][o];
            }
        }
    }
    return mCopy;
}
