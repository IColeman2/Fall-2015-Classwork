import java.util.Arrays;

/**
 * This program finds the ith order statistic of a list of numbers using
 * the command line and an implementation of the insertion sort 
 * algorithm
 */
public class OrderStatistics {
    
	/**
	 * This method takes an array of strings and converts
	 * them to an array of integers
	 * @param strings
	 * @return
	 */
	public static int[] strToIntArray(String strings[]) {
		int result[] = new int[strings.length];
		for(int i=0; i<strings.length; i++) {
			result[i] = Integer.parseInt(strings[i]);
		}
		return result;
	}
	
	/**
	 * This method sorts an array of integers using
	 * the insertion sort algorithm.
	 * @param array
	 */
	public static void insertionSort(int array[]) {
		int value;
		for(int i=1; i<array.length; i++) {
			value = array[i];
		    int j = i;
		    while(j > 0 && array[j-1] > value) {
		    	array[j] = array[j-1];
		    	j--;
		    }
		    array[j] = value;
		}
	}
	
	public static int getOrderStatistic(int arr[], int i) {
		insertionSort(arr); 
		return arr[i-1];
	}
	
    public static void main( String[] args ){
        
    	if(args.length < 2) {
    		System.err.println("Usage: OrderStatistic <ith order value> <list of unique numbers>");
    		System.exit(1);
    	}

    	int ithOrder = Integer.parseInt(args[0]);
    	int numElements = args.length - 1; 

    	if( ithOrder < 1 || ithOrder > numElements) {
    		System.err.printf("The ith order value must be between 1 and %d\n", numElements);
    		System.exit(-1);
    	}

    	int numbers[] = strToIntArray(Arrays.copyOfRange(args, 1, args.length));

    	int ithElement = getOrderStatistic(numbers, ithOrder);

    	System.out.printf("The %dth element is: %d\n", ithOrder, ithElement);
        
    }

}
