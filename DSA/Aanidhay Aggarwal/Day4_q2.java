import java.util.Scanner;

public class Main {
    public static String canBeRearranged(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int maxFreq = 0, minFreq = Integer.MAX_VALUE, maxCount = 0, minCount = 0;
        for (int i : freq) {
            if (i > maxFreq) {
                maxFreq = i;
            }
            if (i < minFreq) {
                minFreq = i;
            }
        }

        for (int i : freq) {
            if (i == maxFreq) {
                maxCount++;
            }
            if (i == minFreq) {
                minCount++;
            }
        }

        if (maxCount > 1) {
            return "invalid";
        } else if (maxFreq - minFreq > 1) {
            return "invalid";
        } else {
            return "valid";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = scanner.next();
        System.out.println(canBeRearranged(s));
    }
}
