package assignment_questions5D4;
import java.util.*;

class PinMismatchException extends Exception{
	public PinMismatchException(String Message) {
		super(Message);
	}
}

public class Assignement16_ATMPIN_validator {
	private static final int CORRECT_PIN = 1234;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Account Holder name: ");
		String name = sc.nextLine();
		int attempts = 0;
		boolean accessGranted = false;
		while(attempts<3) {
			System.out.println("Enter pin: ");
			int enteredPin = sc.nextInt();
			
			if(enteredPin == CORRECT_PIN) {
				System.out.println("Access Granted");
				accessGranted = true;
				break;
			}
			else {
				attempts++;
				try {
					throw new PinMismatchException("Incorrect Pin.Attempt "+attempts+ "of 3"); 
				}
				catch(PinMismatchException e) {
					System.out.println(e.getMessage());
				}
			}
		}
		
		if(!accessGranted) {
			try {
				throw new PinMismatchException("Sorry..Your Account Has been Locked");
			}
			catch(PinMismatchException e) {
				System.out.println(e.getMessage());
			}
		}
		
		sc.close();

	}

}
