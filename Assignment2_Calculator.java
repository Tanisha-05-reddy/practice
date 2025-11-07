package javaD4;
import java.util.Scanner;

public class Assignment2_Calculator {

	public static void main(String[] args) {
		 Scanner scanner = new Scanner(System.in);
		 
	        System.out.print("Enter first number: ");
	        int num1 = scanner.nextInt();
	        System.out.print("Enter second number: ");
	        int num2 = scanner.nextInt();
	        
	        System.out.println("Enter operator:");
	        System.out.println("1. Add");
	        System.out.println("2. Subtract");
	        System.out.println("3. Multiply");
	        System.out.println("4. Divide");

	        int operator = scanner.nextInt();
	        double result;
	        switch (operator) {

	            case 1:
	                result = num1 + num2;
	                System.out.println("Result: " + result);
	                break;
	            case 2:
	                result = num1 - num2;
	                System.out.println("Result: " + result);
	                break;
	            case 3:
	                result = num1 * num2;
	                System.out.println("Result: " + result);
	                break;
	            case 4:           
	                    result = num1 / num2;
	                    System.out.println("Result: " + result);
	                break;
	            default:
	                System.out.println("Invalid operator!");
	        }
	        scanner.close();
	}

}
