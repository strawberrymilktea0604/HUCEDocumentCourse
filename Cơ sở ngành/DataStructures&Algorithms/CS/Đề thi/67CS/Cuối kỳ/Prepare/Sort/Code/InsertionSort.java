import java.util.Arrays;
import java.util.Random;

/**
 * Insertion Sort Algorithm.
 * @author djitz
 *
 */
public class InsertionSort {

	/**
	 * Main method.
	 * @param args
	 */
	public static void main(String[] args) {
		
	    InsertionSort app = new InsertionSort();
		
	    //Generate an integer array of length 7
	    int[] input = app.generateRandomNumbers(7);
		
	    //Before sort
	    System.out.println(Arrays.toString(input));
		
	    //After sort
	    System.out.println(Arrays.toString(app.insertionSort(input)));
	
	}
	
	/**
	 * This method sort the input integer array using insertion sort.
	 * @param input the array of integers to sort.
	 * @return sorted input array of integers.
	 */
	private int[] insertionSort(int[] input){
		
	    int temp;
		
	    for (int i = 1; i < input.length; i++) {
		    for(int j = i ; j > 0 ; j--){
			    if(input[j] < input[j-1]){
				    temp = input[j];
				    input[j] = input[j-1];
				    input[j-1] = temp;
			    }
		    }
	    }
	    return input;
	}
	
	/**
	 * This method generate array of random integers with length n. 
	 * @param n the length of the array to generate.
	 * @return array of random integers with length n. 
	 */
	private int[] generateRandomNumbers(int n){
		
	    int[] result = new int[n];
	    Random random = new Random();
		
	    for (int i = 0; i < result.length; i++) {
		    result[i] = random.nextInt(n * 10);
	    }
	
	    return result;
	}

}
