import java.util.Set;
import java.util.HashSet;

public class WordBreak {

    public static String canSegmentString(String s, Set<String> dictionary) {
        int n = s.length();
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

        return dp[n] ? "YES" : "NO";
    }

    public static void main(String[] args) {
        String string = "applepie";
        Set<String> dictionary = new HashSet<>();
        dictionary.add("apple");
        dictionary.add("pie");

        System.out.println(canSegmentString(string, dictionary)); 
    }
}
