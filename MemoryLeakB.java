package unl.cse.memory;

import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class MemoryLeakB {

	public static final Integer SIZE = 50000;
	
	private final int numberOfTrials;
	private Set<int[]> allSets;
	private Random random;
	
	public MemoryLeakB(int numberOfTrials) {
		this.numberOfTrials = numberOfTrials;
		this.allSets = new HashSet<int[]>();
		this.random = new Random();
	}
	
	private int[] randomArray(int n) {
		int result[] = new int[n];
		for(int i=0; i<n; i++) {
			result[i] = this.random.nextInt();
		}
		return result;
	}
	
	public void runStats() {
		for(int i=0; i<this.numberOfTrials; i++) {			
			int randArray[] = randomArray(SIZE);
			int randNum = random.nextInt(SIZE);
			//Finds that ithOrder number and prints the results
			int ithOrder = OrderStatisticUtils.quickSelect(randArray, 0, SIZE-1, randNum);
			//System.out.println(String.format("The %5dth element of the randomly generated array is %d", randNum, ithOrder));
			//AND we place it into a set to "remember it":
			this.allSets.add(randArray);
		}
	}
	
	public static void main(String args[]) {
		if(args.length != 1) {
			System.err.println("Usage: MemoryLeakB <number of random lists>");
			System.exit(1);
		}
		int m = Integer.parseInt(args[0]);
		MemoryLeakB demo = new MemoryLeakB(m);
		demo.runStats();
	}
}
