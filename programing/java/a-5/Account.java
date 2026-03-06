import java.util.Scanner;

class Account {
    String accountNumber;
    double balance;

    // Parameterized Constructor with Validation
    Account(String accNo, double bal) {
        if (accNo == null || accNo.isEmpty()) {
            System.out.println("Error: Account number cannot be null or empty");
        } 
        else if (bal < 0) {
            System.out.println("Error: Balance cannot be negative");
        } 
        else {
            accountNumber = accNo;
            balance = bal;
            System.out.println("Account Created Successfully");
            display();
        }
    }

    void display() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Balance: " + balance);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Account Number: ");
        String accNo = sc.nextLine();

        System.out.print("Enter Balance: ");
        double bal = sc.nextDouble();

        Account a1 = new Account(accNo, bal);

        sc.close();
    }
}