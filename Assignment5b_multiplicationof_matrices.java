package javaD4;
import java.util.Scanner;

public class Assignment5b_multiplicationof_matrices {

	public static void main(String[] args) {
		int[][] arr1=new int[2][2];
		int[][] arr2=new int[2][2];
		Scanner sc = new Scanner(System.in);
        System.out.println("Enter arr1 elements: ");
        for(int i=0; i<2; i++) {
        	for(int j=0; j<2; j++) {
        		arr1[i][j] = sc.nextInt();
        	}
	}
        System.out.println("Enter arr2 elements: ");
        for(int i=0; i<2; i++) {
        	for(int j=0; j<2; j++) {
        		arr2[i][j] = sc.nextInt();
        	}
        }
        int[][] result = new int[2][2];
        for(int i=0; i<2; i++) {
        	for(int j=0; j<2; j++) {
        		result[i][j] = 0;
        		for(int k=0; k<2; k++) {
        			result[i][j]+=arr1[i][k]*arr2[k][j];
        		}
        	}
        }
        for(int i=0; i<2; i++) {
        	for(int j=0; j<2; j++) {
        		System.out.print(result[i][j]+" ");
        	}
        }
        System.out.println("\n");
	}
}
