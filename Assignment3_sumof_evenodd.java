package javaD4;
import java.util.Scanner;

public class Assignment3_sumof_evenodd {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of integers: ");
        
        int count = scanner.nextInt();
        int evenSum = 0;
        int oddSum = 0;
        for (int i = 1; i <= count; i++) {
            System.out.print("Enter number " + i + ": ");
            int num = scanner.nextInt();
            if (num % 2 == 0) {
                evenSum += num;
            } else {
                oddSum += num;
            }
        }
        System.out.println("Sum of even numbers: " + evenSum);
        System.out.println("Sum of odd numbers: " + oddSum);
        scanner.close();
	}
}
