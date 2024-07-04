import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the string:");
        String s = scanner.nextLine();

        System.out.println("Enter the number of dictionary words:");
        int n = scanner.nextInt();
        scanner.nextLine();

        String[] wordDict = new String[n];
        System.out.println("Enter the dictionary words:");
        for (int i = 0; i < n; i++) {
            wordDict[i] = scanner.nextLine();
        }

        System.out.println(wordBreak(s, wordDict));
    }

    public static String wordBreak(String s, String[] wordDict) {
        Set<String> set = new HashSet<>(Arrays.asList(wordDict));
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && set.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()] ? "YES" : "NO";
    }
}
