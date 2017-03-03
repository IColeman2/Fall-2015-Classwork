package unl.cse.memory;

import java.util.Scanner;

public class Statistics {
	
	//Fills numList with random numbers
	public static int[] buildArray(int size)
	{
		int result[] = new int[size];
		System.out.println("Enter your list of numbers: ");
		Scanner s = new Scanner(System.in);
		int i=0;
		while(i < size && s.hasNext()) {
			result[i] = s.nextInt();
			i++;
	    }
		return result;
	}

	//Write your code here to find the mean of numList
    
	public static double findMean(int array[], int sizeOfArray)
	{
		int sum = 0;
		int numberOfElements = 0;
		for(int i:array) {
			sum+=i;
			numberOfElements ++;
		}
		return((double)(sum)/numberOfElements);
	}

	public static int findMax(int array[])
	{
		int max = 0;
		for(int i:array) {
			if(i>max) {
				max = i;
			}
		}
		return(max);
	}

	public static int findMin(int array[])
	{
		int min = 0;
		for(int i:array) {
			if(i<min) {
				min = i;
			}
		}
		return(min);
	}
    
	public static void main(String args[]) {

	    int min = 0, max = 0, size;
	    double mean = 0.0;
	    
	    System.out.println("Enter the amount of numbers you'd like to find the stats for: ");
	    Scanner s = new Scanner(System.in);
	    size = s.nextInt();
	    
	    int numberList[]=buildArray(size);
	    
	    /*Pass the appropriate variables into your functions here*/
	    min = findMin(numberList);
	    max = findMax(numberList);
	    mean = findMean(numberList, size);

	    System.out.println("Min: "+min);
	    System.out.println("Max: "+max);
	    System.out.println("Mean: "+mean);

	}
}
