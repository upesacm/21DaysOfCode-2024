import java.util.HashSet;
import java.util.Set;

public class Day13_Q1 {
    public static void main(String[] args) {
        String string = "applepie";
        String[] dictionaryArray = { "apple", "pie" };

        Set<String> dictionary = new HashSet<>();
        for (String word : dictionaryArray) {
            dictionary.add(word);
        }

        if (canSegmentString(string, dictionary)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean canSegmentString(String s, Set<String> dictionary) {
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dictionary.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
}
