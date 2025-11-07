package practice;
import java.util.Scanner;

//Interface
interface Bank {
 double rateOfInterest = 6.5; // fixed rate of interest

 void createAccount(String name, int accNo);
 void credit(double amount);
 void debit(double amount);
 void transfer(Bank toBank, double amount);
 void miniStatement();
}

//SBI Bank implementation
class SBI implements Bank {
 String name;
 int accNo;
 double balance;

 public void createAccount(String name, int accNo) {
     this.name = name;
     this.accNo = accNo;
     this.balance = 0;
     System.out.println("SBI Account created for " + name + " with Account No: " + accNo);
 }

 public void credit(double amount) {
     balance += amount;
     System.out.println("Credited " + amount + ". Current balance: " + balance);
 }

 public void debit(double amount) {
     if (amount <= balance) {
         balance -= amount;
         System.out.println("Debited " + amount + ". Current balance: " + balance);
     } else {
         System.out.println("Insufficient balance!");
     }
 }

 public void transfer(Bank toBank, double amount) {
     if (amount <= balance) {
         balance -= amount;
         toBank.credit(amount);
         System.out.println("Transferred " + amount + " successfully!");
     } else {
         System.out.println("Insufficient balance for transfer!");
     }
 }

 public void miniStatement() {
     System.out.println("----- SBI MINI STATEMENT -----");
     System.out.println("Account Holder: " + name);
     System.out.println("Account No: " + accNo);
     System.out.println("Balance: " + balance);
     System.out.println("Interest Rate: " + rateOfInterest + "%");
 }
}

//Axis Bank implementation
class Axis implements Bank {
 String name;
 int accNo;
 double balance;

 public void createAccount(String name, int accNo) {
     this.name = name;
     this.accNo = accNo;
     this.balance = 0;
     System.out.println("Axis Account created for " + name + " with Account No: " + accNo);
 }

 public void credit(double amount) {
     balance += amount;
     System.out.println("Credited " + amount + ". Current balance: " + balance);
 }

 public void debit(double amount) {
     if (amount <= balance) {
         balance -= amount;
         System.out.println("Debited " + amount + ". Current balance: " + balance);
     } else {
         System.out.println("Insufficient balance!");
     }
 }

 public void transfer(Bank toBank, double amount) {
     if (amount <= balance) {
         balance -= amount;
         toBank.credit(amount);
         System.out.println("Transferred " + amount + " successfully!");
     } else {
         System.out.println("Insufficient balance for transfer!");
     }
 }

 public void miniStatement() {
     System.out.println("----- AXIS MINI STATEMENT -----");
     System.out.println("Account Holder: " + name);
     System.out.println("Account No: " + accNo);
     System.out.println("Balance: " + balance);
     System.out.println("Interest Rate: " + rateOfInterest + "%");
 }
}


public class Bank_interface_11 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

        // Late Binding (Dynamic Method Dispatch)
        Bank bank;

        System.out.print("Enter bank name (SBI/Axis): ");
        String choice = sc.nextLine();

        if (choice.equalsIgnoreCase("SBI")) {
            bank = new SBI();  // Late binding
        } else {
            bank = new Axis(); // Late binding
        }

        // Operations
        bank.createAccount("Surena", 1001);
        bank.credit(2000);
        bank.debit(500);
        bank.miniStatement();

        sc.close();

	}

}
