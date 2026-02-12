import java.util.Scanner;
import java.util.HashSet;

public class LongestSubstring {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = sc.nextLine();

        int maxLength = 0;
        int start = 0;
        HashSet<Character> set = new HashSet<>();

        for (int end = 0; end < s.length(); end++) {
            while (set.contains(s.charAt(end))) {
                set.remove(s.charAt(start));
                start++;
            }
            set.add(s.charAt(end));
            maxLength = Math.max(maxLength, end - start + 1);
        }

        System.out.println("Length of longest substring: " + maxLength);
    }
}
