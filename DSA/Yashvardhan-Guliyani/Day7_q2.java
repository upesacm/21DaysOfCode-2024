import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        System.out.println(minMaxOperation(str));
        scanner.close();
    }
    public static int minMaxOperation(String str) {
        int n = str.length();
        int[] prefixY = new int[n + 1];
        int[] suffixY = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixY[i + 1] = prefixY[i] + (str.charAt(i) == 'y' ? 1 : 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            suffixY[i] = suffixY[i + 1] + (str.charAt(i) == 'y' ? 1 : 0);
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                int remainingX = n - i - j - (prefixY[n] - prefixY[i] - suffixY[n - j]);
                int removedY = prefixY[i] + suffixY[n - j];
                result = Math.min(result, Math.max(remainingX, removedY));
            }
        }
        return result;
    }
}
