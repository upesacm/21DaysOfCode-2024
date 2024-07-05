import java.util.*;

public class StringSegmentation {
    
    public static boolean canSegment(String s, List<String> dictionary) {
        if (s == null || s.length() == 0) {
            return true;
        }
        
                boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true; // Base case: empty substring is segmented
        
        
        for (int i = 1; i <= s.length(); i++) {
            // Check all substrings ending at current index i
            for (int j = 0; j < i; j++) {
                if (dp[j] && dictionary.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break; // Break early if we find a valid segmentation
                }
            }
        }
        
        return dp[s.length()];
    }
    
    public static void main(String[] args) {
        String str = "applepie";
        List<String> dictionary = new ArrayList<>();
        dictionary.add("apple");
        dictionary.add("pie");
        if (canSegment(str, dictionary)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
