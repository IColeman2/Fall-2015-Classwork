package unl.cse.memory;

import java.util.Random;

public class MemoryLeakA {

	public static final Integer SIZE = 50000;
	
	public static int[] randomArray(int n) {
		int result[] = new int[n];
		Random r = new Random();
		for(int i=0; i<n; i++) {
			result[i] = r.nextInt();
		}
		return result;
	}
	
	public static void main(String args[]) {
		if(args.length != 1) {
			System.err.println("Usage: MemoryLeakA <number of random lists>");
			System.exit(1);
		}
		int m = Integer.parseInt(args[0]);
		Random r = new Random();
		for(int i=0; i<m; i++) {
			
			int randArray[] = randomArray(SIZE);
			int randNum = r.nextInt(SIZE);

			//Finds that ithOrder number and prints the results
			//int ithOrder = OrderStatisticUtils.quickSelect(randArray, 0, SIZE-1, randNum);
			//System.out.println(String.format("The %5dth element of the randomly generated array is %d", randNum, ithOrder));
		}
	}
}
