//Question-2
//Author - Ayush Dey

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Q2 {

    public static String isValidRearrangedString(String s) {
        Map<Character, Integer> charCount = new HashMap<>();

        // Count occurrences of each character
        for (char c : s.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }

        int oddCount = 0;
        for (int count : charCount.values()) {
            if (count % 2 != 0) {
                oddCount++;
                if (oddCount > 1) {
                    return "invalid";
                }
            }
        }

        return "valid";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        String result = isValidRearrangedString(input);
        System.out.println(result);
    }
}
