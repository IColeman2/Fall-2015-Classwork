/**
*I Coleman and Jack Johnson
*icoleman@huskers.unl.edu / jjohnson@huskers.unl.edu
*11/4/2015
*Assignment 4, Problem 3:
*A suite of simple array utilities
*/

package unl.cse;
 
import java.util.Arrays;
 
public class ArrayUtils {
 
    public static double mean(int a[]) {
        int n = a.length;
        int sumOfValues = 0;
        int i;
 
        for(i = 0; i<n; i++) {
            sumOfValues += a[i];
        }
 
        return((double)sumOfValues/n);
    }
 
    public static double[] windowMeans(int a[], int m) {
        int n = a.length;
        if(n<m) {
            return null;
        }
        if(m<1) {
            return null;
        }
 
        int sizeOfResult = n-m+1;
        int i;
        int j;
        int sumOfValues;
        int endValue;
        double windowMean;
 
        double[] result = new double[sizeOfResult];
 
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
 
    public static int mode(int a[]) {
        int n = a.length;
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
        return a[i];
    }
 
 //   private static int getMultiplicity(int a[], int item) {
 //   }
 
    private static boolean contains(int a[], int n, int x) {
        for(int i = 0; i<a.length; i++){
            if(a[i] == n){
                return true;
            }
        }
        return false;
    }
 
    public static int [] getAllModes(int a[]) {
        int n = a.length;
        int[] temp = new int[n];
        int maxNumberOfAppearances=0;
        int i;
        int j;
        int numberOfModes = 0;
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
            if(numberOfAppearances==maxNumberOfAppearances && contains(temp, a[i], n) == false) {
                temp[numberOfModes]=a[i];
                numberOfModes++;
            }
        }
        int[] result = new int[numberOfModes];
        for(i=0; i<numberOfModes; i++) {
            result[i] = temp[i];
        }
 
        return result;
 
    }
 
    public static int[] filter(int a[], int threshold) {
        int n = a.length;
        int[] temp = new int[n];
        int i;
        int resultSizeCounter = 0;
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
 
        int[] result = new int[resultSizeCounter];
        for(i=0; i<resultSizeCounter; i++) {
            result[i] = temp[i];
        }
 
        return result;
    }
 
    public static int[] append(int a[], int b[]) {
        int sizeA = a.length;
        int sizeB = b.length;
        int resultSize = sizeA+sizeB;
        int[] result = new int[resultSize];
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
 
 
}
