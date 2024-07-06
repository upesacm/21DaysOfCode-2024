import java.util.*;

public class WordBreak {
    public static String canSegmentString(String s, Set<String> dictionary) {
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true; // Base case: empty string

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dictionary.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n] ? "YES" : "NO";
    }

    public static void main(String[] args) {
        String s = "applepie";
        Set<String> dictionary = new HashSet<>(Arrays.asList("apple", "pie"));

        System.out.println(canSegmentString(s, dictionary)); // Output: YES
    }
}
