import java.util.Scanner;

public class SumOfTenNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;

        System.out.println("Enter 10 natural numbers:");
        for (int i = 1; i <= 10; i++) {
            int num = sc.nextInt();
            sum += num;
        }

        System.out.println("Sum = " + sum);
    }
}
