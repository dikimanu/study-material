import java.util.Scanner;

public class StringEqualParts {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the string: ");
        String str = sc.nextLine();

        System.out.print("Enter number of parts: ");
        int n = sc.nextInt();

        int len = str.length();

        if (len % n != 0) {
            System.out.println("String cannot be divided into equal parts.");
            return;
        }

        int partSize = len / n;
        for (int i = 0; i < len; i += partSize) {
            System.out.println(str.substring(i, i + partSize));
        }
    }
}
