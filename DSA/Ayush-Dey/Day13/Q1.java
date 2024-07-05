// Question-1
// Author - Ayush Dey

import java.util.*;

public class Q1 {
    public static String wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()]? "YES" : "NO";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String string = scanner.nextLine();

        System.out.print("Enter dictionary words (separated by space): ");
        String[] dictWords = scanner.nextLine().split(" ");
        List<String> dictionary = Arrays.asList(dictWords);

        System.out.println(wordBreak(string, dictionary));
    }
}