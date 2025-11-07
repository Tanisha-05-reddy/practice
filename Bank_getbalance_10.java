package demo;
class Sbi{
    public int getBalance() {
    	return 0; 
    }
}

class BankA extends Sbi {
    public int getBalance() {
        return 1000; 
    }
}

class BankB extends Sbi {
    public int getBalance() {
        return 1500; 
    }
}

class BankC extends Sbi {
    public int getBalance() {
        return 2000; 
    }
}


public class Bank_getbalance_10 {
	public static void main(String[] args) {
		Sbi bankA = new BankA();
		Sbi bankB = new BankB();
		Sbi bankC = new BankC();
		
		System.out.println("Balance in BankA: "+ bankA.getBalance());
		System.out.println("Balance in BankB: "+ bankB.getBalance());
		System.out.println("Balance in BankC: "+ bankC.getBalance());
	}
}
