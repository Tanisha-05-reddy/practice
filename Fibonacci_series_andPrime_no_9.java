package demo;
import java.util.Scanner;
public class Fibonacci_series_andPrime_no_9 {
	 static boolean isPrime(int num) {
	        if (num < 2) return false;
	        for (int i = 2; i <= Math.sqrt(num); i++) {
	            if (num % i == 0) return false;
	        }
	        return true;
}
	public static void main(String[] args) {
		  Scanner scanner = new Scanner(System.in);

	        System.out.print("Enter value of n: ");
	        int n = scanner.nextInt();

	        int a = 0, b = 1;

	        System.out.println("Prime numbers in Fibonacci series up to " + n + " are:");

	        while (a <= n) {
	            if (isPrime(a)) {
	                System.out.print(a + " ");
	            }
	            int next = a + b;
	            a = b;
	            b = next;
	        }

	        scanner.close();

	}

}
