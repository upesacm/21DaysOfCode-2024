// // https://www.hackerrank.com/contests/21-days-of-code-2024-quiz1/challenges/binary-puzzle-quest
// Given a dualistic string str having character 'x' and 'y', you have to perform 2 operations on it:
// Remove some(possibly x) characters from the beginning of str.
// Remove some(possibly x) characters from the end of str.
// Let dig0 be the number of characters 'x' left in str and dig1 be the number of characters 'y' removed from Str. Your task is to find the minimum value of max(dig0,dig1).
// Input Format

// Input: str = "yxyyyxyyx"

// Output: 1

// Explanation: It's possible to remove two characters from the beginning and one character from the end. Only one y is deleted, only one x remains, so the cost is 1. It can be proved that this is the most optimal answer.

// Constraints

// 1 <= str.size() <= 105

// Output Format

// Input: str = "yxxyxxyxxyxxy"

// Output: 3

// Explanation: It's possible to remove three characters from the beginning and six characters from the end. Two characters x remain, three characters y are deleted, so the cost is 3. It can be proved that this is the most optimal answer.

// Sample Input 0
// yxyyyxyyx
// Sample Output 0
// 1

// Sample Input 1
// yxxyxxyxxyxxy
// Sample Output 1
// 3

import java.io.*;
import java.util.*;

public class Solution {

    public static int findMinValue(String str) {
        int n = str.length();
        int totalX = 0, totalY = 0;

        for (char c : str.toCharArray()) {
            if (c == 'x') totalX++;
            else if (c == 'y') totalY++;
        }

        int leftX = 0, rightX = totalX;
        int leftY = 0, rightY = totalY;
        int minValue = Integer.MAX_VALUE;

        for (int i = 0; i <= n; i++) {
            int maxDig = Math.max(rightX, leftY);
            minValue = Math.min(minValue, maxDig);

            if (i < n) {
                if (str.charAt(i) == 'x') {
                    leftX++;
                    rightX--;
                } else {
                    leftY++;
                    rightY--;
                }
            }
        }

        return minValue;
    }
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        scanner.close();

        int result = findMinValue(str);
        System.out.println(result);
    }
}
