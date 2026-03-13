// BankAccount class
class BankAccount {
    int accountNumber;
    double balance;
    double interestRate;

    // Constructor
    BankAccount(int accountNumber, double balance, double interestRate) {
        this.accountNumber = accountNumber;
        this.balance = balance;
        this.interestRate = interestRate;
    }

    // Deposit method
    void deposit(double amount) {
        balance = balance + amount;
        System.out.println("Deposited: " + amount);
        System.out.println("Current Balance: " + balance);
    }
}

// SavingsAccount class extending BankAccount
class SavingsAccount extends BankAccount {
    double minimumBalance;

    // Constructor
    SavingsAccount(int accountNumber, double balance, double interestRate, double minimumBalance) {
        super(accountNumber, balance, interestRate);
        this.minimumBalance = minimumBalance;
    }

    // Withdraw method
    void withdraw(double amount) {
        if ((balance - amount) >= minimumBalance) {
            balance = balance - amount;
            System.out.println("Withdrawn: " + amount);
            System.out.println("Remaining Balance: " + balance);
        } else {
            System.out.println("Cannot withdraw. Minimum balance must be maintained.");
        }
    }
}

// FixedDepositAccount class extending SavingsAccount
class FixedDepositAccount extends SavingsAccount {
    int term; // in years

    // Constructor
    FixedDepositAccount(int accountNumber, double balance, double interestRate, double minimumBalance, int term) {
        super(accountNumber, balance, interestRate, minimumBalance);
        this.term = term;
    }

    // Method to calculate interest
    double getInterest() {
        return balance * interestRate * term;
    }
}

// Main class
public class Bank {
    public static void main(String[] args) {

        // Object of BankAccount
        BankAccount b1 = new BankAccount(1001, 5000, 0.05);
        b1.deposit(1000);

        System.out.println();

        // Object of SavingsAccount
        SavingsAccount s1 = new SavingsAccount(2001, 8000, 0.04, 2000);
        s1.deposit(500);
        s1.withdraw(3000);

        System.out.println();

        // Object of FixedDepositAccount
        FixedDepositAccount f1 = new FixedDepositAccount(3001, 10000, 0.06, 1000, 2);
        double interest = f1.getInterest();
        System.out.println("Interest earned: " + interest);
    }
}