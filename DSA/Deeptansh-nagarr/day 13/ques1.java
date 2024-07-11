// Determine if a string can be segmented into a space-separated sequence of dictionary words.

// Inputs:
// A string and a dictionary of words.
// Output:
// "YES" if the string can be segmented, otherwise "NO".
// Example:
// string = "applepie"

// dictionary = ["apple", "pie"]

// Output: YES

import java.util.*;

public class day13ques1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String s = sc.nextLine();
        System.out.print("Enter the dictionary words: ");
        String[] dictionaryWords = sc.nextLine().split(" ");
        Set<String> dictionary = new HashSet<>(Arrays.asList(dictionaryWords));
        if (canSegmentString(s, dictionary)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean canSegmentString(String s, Set<String> dictionary) {
        int n = s.length();
        if (n == 0) return true;
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dictionary.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
