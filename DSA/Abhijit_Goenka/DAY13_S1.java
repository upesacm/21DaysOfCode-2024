import java.util.*;
class DAY13_S1 
{
    public static String canSegmentString(String s, Set<String> wordDict) 
    {
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) 
            {
                if (dp[j] && wordDict.contains(s.substring(j, i))) 
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n] ? "YES" : "NO";
    }
    public static void main(String[] args) 
    {
        String s = "apples";
        Set<String> wordDict = new HashSet<>(Arrays.asList("apple", "pie"));

        System.out.println(canSegmentString(s, wordDict)); 
    }
}

