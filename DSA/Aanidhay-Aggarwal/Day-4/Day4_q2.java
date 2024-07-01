import java.util.Scanner;

public class Main {
    public static String canBeRearranged(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int maxFreq = 0, minFreq = Integer.MAX_VALUE;
        for (int i : freq) {
            if (i > 0) {
                if (i > maxFreq) {
                    maxFreq = i;
                }
                if (i < minFreq) {
                    minFreq = i;
                }
            }
        }

        if (maxFreq == minFreq) {
            return "valid";
        } else if (maxFreq - minFreq == 1) {
            int maxCount = 0, minCount = 0;
            for (int i : freq) {
                if (i == maxFreq) {
                    maxCount++;
                }
                if (i == minFreq) {
                    minCount++;
                }
            }
            if (maxCount == 1 || minCount == 1) {
                return "valid";
            } else {
                return "invalid";
            }
        } else {
            return "invalid";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = scanner.next();
        System.out.println(canBeRearranged(s));
    }
}
