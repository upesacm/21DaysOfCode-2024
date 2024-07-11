import java.util.HashSet;
import java.util.Set;

public class WordBreak {

    public static void main(String[] args) {
        String str = "applepie";
        Set<String> dictionary = new HashSet<>();
        dictionary.add("apple");
        dictionary.add("pie");

        if (wordBreak(str, dictionary)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean wordBreak(String str, Set<String> dictionary) {
        int n = str.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true; // base case

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dictionary.contains(str.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
}
