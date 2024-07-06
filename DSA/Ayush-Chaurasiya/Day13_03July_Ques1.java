import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Day13_03July_Ques1 {
    public static boolean stringSegmentation(String str, List<String> dict) {
        int n = str.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true; 

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.contains(str.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

    public static void main(String[] args) {
        List<String> dict = new ArrayList<>() {{
            add("apple");
            add("pie");
        }};

        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        scanner.close();

        if (stringSegmentation(str, dict)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
