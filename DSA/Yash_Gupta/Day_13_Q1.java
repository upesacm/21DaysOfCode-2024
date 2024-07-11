public class Day_13_Q1 {

    public static boolean wordBreak(String s, String[] wordDict) {
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true; 

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && containsWord(s.substring(j, i), wordDict)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    private static boolean containsWord(String word, String[] wordDict) {
        for (String dictWord : wordDict) {
            if (dictWord.equals(word)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        String s1 = "applepie";
        String[] wordDict1 = {"apple", "pie"};
        System.out.println(wordBreak(s1, wordDict1)); 
    }
}
