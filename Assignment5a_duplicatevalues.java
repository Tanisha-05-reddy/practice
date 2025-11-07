package javaD4;

public class Assignment5a_duplicatevalues {

	public static void main(String[] args) {
		  int[] arr = {9, 7, 3, 4, 9, 7, 1, 3};
	        System.out.println("Duplicate values in the array are:");

	        for (int i = 0; i < arr.length; i++) {
	            for (int j = i + 1; j < arr.length; j++) {
	                if (arr[i] == arr[j]) {
	                    System.out.println(arr[i]);
	                    break; 
	                }
	            }
	        }

	}

}
