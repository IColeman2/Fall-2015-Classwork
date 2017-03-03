/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/4/2015
*Assignment 4, Problem 4:
*A suite of matrix utilities
*/
package unl.cse;


public class MatrixUtils {

	//A method that creates a (square) identity matrix of size nxn
    public static int[][] getIdentityMatrix(int n) {
	    int i, o;
	    int[][] outerMatrix = new int[n][n];
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
	
	//A function to determine if a given matrix is a permutation matrix, returning "true" if it is and "false" if it's not
    public static boolean isPermutationMatrix(int m[][]) {
    	 int i, o, countH, countV;
 	    for(i=0; i<m.length; i++){
 	        countH = 0;
 	        countV = 0;
 	        for(o=0; o<m.length; o++){
 	            if(m[i][o] == 1 || m[i][o] == 0 || m[o][i] == 1 || m[o][i] == 0){
 	                if(m[i][o] == 1){
 	                    countH++;
 	                }
 	                if(m[o][i] == 1){
 	                    countV++;
 	                }
 	            }else{
 	                return false;
 	            }
 	        }
 	        if(countV != 1 || countH != 1){
 	            return false;
 	        }
 	    }
 	    return true;
    }
	
	//A method to  determine  if  a  given  square  matrix  is symmetric
    public static boolean isSymmetric(int m[][]) {
	    int i, o;
	    for(i=0; i<m.length; i++){
	        for(o=0; o<m.length; o++){
	            if(m[i][o] != m[o][i]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
	
	//A method to compute the trace of a matrix
    public static int trace(int m[][]) {
	    int i, o;
	    int trace = 0;
	    for(i=0; i<m.length; i++){
	        for(o=0; o<m.length; o++){
	            if(i == o){
	                trace = trace + m[i][o];
	            }
	        }
	    }
	    return trace;
    }
	
	//A method to flip a matrix along the diagonal, or transpose it
    public static void transpose(int m[][]) {
	    int i, o, placeholder;
	    for(i=0; i<m.length; i++){
	        for(o=0; o<i; o++){
	            placeholder = m[i][o];
	            m[i][o] = m[o][i];
	            m[o][i] = placeholder;
	        }
	    }
    }

	//A method to transpose a matrix and create a new matrix representing the transpose
    public static int[][] transposeCopy(int m[][]) {
	    int i, o;
	    int[][] mcopy = new int[m.length][m.length];
	    for(i=0; i<m.length; i++){
	        for(o=0; o<m.length; o++){
	            mcopy[i][o] = m[i][o];
	        }
	    }
	    int[][] aCopy = mcopy;
	    transpose(aCopy);
	    return aCopy;
    }
	
	//A method to resize a matrix
    public static int[][] matrixCopy(int m[][], int p, int q) {
	    int i, o;
	    int[][] mCopy = new int[p][q];
	    for(i=0; i<p; i++){
	        for(o=0; o<q; o++){
	            if(i>=m.length || o>=m.length){
	                mCopy[i][o] = 0;
	            }
	            else{
	                mCopy[i][o] = m[i][o];
	            }
	        }
	    }
	    return mCopy;
	}
}



