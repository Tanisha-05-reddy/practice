package javaD4;
import java.util.Scanner;

public class Assignment1_electricitybill {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
        System.out.print("Enter old meter reading: ");
        int oldReading = scanner.nextInt();

        System.out.print("Enter current meter reading: ");
        int currentReading = scanner.nextInt();
        
        int units = currentReading - oldReading;
        double bill = 0;

        if (units <= 0) {
            System.out.println("Invalid reading. No consumption or wrong input.");
        } else if (units <= 50) {
            bill = units * 1;
        } else if (units <= 100) {
            bill = (50 * 1) + ((units - 50) * 2);
        } else if (units <= 200) {
            bill = (50 * 1) + (50 * 2) + ((units - 100) * 3);
        } else if (units <= 400) {
            bill = (50 * 1) + (50 * 2) + (100 * 3) + ((units - 200) * 4);
        } else {
            bill = (50 * 1) + (50 * 2) + (100 * 3) + (200 * 4) + ((units - 400) * 5);
        }
        System.out.println("Total units consumed: " + units);
        System.out.println("Electricity bill amount: ₹" + bill);

        scanner.close();
	}

}
