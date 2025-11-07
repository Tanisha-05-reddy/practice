package demo;
import java.util.Scanner;
public class Bankapplication {

	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);

	        // Maximum 10 accounts for simplicity
	        String[] names = new String[10];
	        String[] aadhar = new String[10];
	        String[] pan = new String[10];
	        int[] accountNumber = new int[10];
	        double[] balance = new double[10];
	        int totalAccounts = 0;
	        int accNoCounter = 1001; // starting account number

	        char cont = 'y';

	        while (cont == 'y' || cont == 'Y') {
	            System.out.println("\n---- BANK MENU ----");
	            System.out.println("1. Create Account");
	            System.out.println("2. Credit Amount");
	            System.out.println("3. Debit Amount");
	            System.out.println("4. Balance Enquiry");
	            System.out.println("5. Transfer Amount");
	            System.out.println("6. Exit");
	            System.out.print("Enter your choice: ");
	            int choice = sc.nextInt();

	            switch (choice) {
	                case 1: // Account creation
	                    if (totalAccounts < 10) {
	                        sc.nextLine(); // clear buffer
	                        System.out.print("Enter Name: ");
	                        names[totalAccounts] = sc.nextLine();
	                        System.out.print("Enter Aadhar Number: ");
	                        aadhar[totalAccounts] = sc.nextLine();
	                        System.out.print("Enter PAN Number: ");
	                        pan[totalAccounts] = sc.nextLine();

	                        accountNumber[totalAccounts] = accNoCounter++;
	                        balance[totalAccounts] = 0.0;
	                        System.out.println("Account created successfully! Your Account Number: " + accountNumber[totalAccounts]);
	                        totalAccounts++;
	                    } else {
	                        System.out.println("Maximum accounts reached!");
	                    }
	                    break;

	                case 2: // Credit amount
	                    System.out.print("Enter Account Number: ");
	                    int accCredit = sc.nextInt();
	                    System.out.print("Enter Amount to Credit: ");
	                    double creditAmt = sc.nextDouble();
	                    boolean foundCredit = false;

	                    for (int i = 0; i < totalAccounts; i++) {
	                        if (accountNumber[i] == accCredit) {
	                            balance[i] += creditAmt;
	                            System.out.println("Amount credited successfully! New Balance: " + balance[i]);
	                            foundCredit = true;
	                            break;
	                        }
	                    }
	                    if (!foundCredit) System.out.println("Invalid Account Number!");
	                    break;

	                case 3: // Debit amount
	                    System.out.print("Enter Account Number: ");
	                    int accDebit = sc.nextInt();
	                    System.out.print("Enter Amount to Debit: ");
	                    double debitAmt = sc.nextDouble();
	                    boolean foundDebit = false;

	                    for (int i = 0; i < totalAccounts; i++) {
	                        if (accountNumber[i] == accDebit) {
	                            if (balance[i] >= debitAmt) {
	                                balance[i] -= debitAmt;
	                                System.out.println("Amount debited successfully! New Balance: " + balance[i]);
	                            } else {
	                                System.out.println("Insufficient Balance!");
	                            }
	                            foundDebit = true;
	                            break;
	                        }
	                    }
	                    if (!foundDebit) System.out.println("Invalid Account Number!");
	                    break;

	                case 4: // Balance enquiry
	                    System.out.print("Enter Account Number: ");
	                    int accBal = sc.nextInt();
	                    boolean foundBal = false;

	                    for (int i = 0; i < totalAccounts; i++) {
	                        if (accountNumber[i] == accBal) {
	                            System.out.println("Account Holder: " + names[i]);
	                            System.out.println("Current Balance: " + balance[i]);
	                            foundBal = true;
	                            break;
	                        }
	                    }
	                    if (!foundBal) System.out.println("Invalid Account Number!");
	                    break;

	                case 5: // Transfer amount
	                    System.out.print("Enter From Account Number: ");
	                    int fromAcc = sc.nextInt();
	                    System.out.print("Enter To Account Number: ");
	                    int toAcc = sc.nextInt();
	                    System.out.print("Enter Amount to Transfer: ");
	                    double amt = sc.nextDouble();

	                    int fromIndex = -1, toIndex = -1;

	                    for (int i = 0; i < totalAccounts; i++) {
	                        if (accountNumber[i] == fromAcc) fromIndex = i;
	                        if (accountNumber[i] == toAcc) toIndex = i;
	                    }

	                    if (fromIndex == -1 || toIndex == -1) {
	                        System.out.println("Invalid Account Number(s)!");
	                    } else if (balance[fromIndex] < amt) {
	                        System.out.println("Insufficient Balance!");
	                    } else {
	                        balance[fromIndex] -= amt;
	                        balance[toIndex] += amt;
	                        System.out.println("Transfer successful! New Balance of " + fromAcc + ": " + balance[fromIndex]);
	                    }
	                    break;

	                case 6:
	                    System.out.println("Thank you for using the bank system!");
	                    cont = 'n';
	                    break;

	                default:
	                    System.out.println("Invalid choice! Please try again.");
	            }

	            if (cont != 'n') {
	                System.out.print("\nDo you want to continue? (y/n): ");
	                cont = sc.next().charAt(0);
	            }
	        }

	        sc.close();
     
	}

}
