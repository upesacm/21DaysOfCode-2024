// Question 2: Determine if a string can be rearranged such that all characters have the same frequency. If one removal can achieve this, return "valid", otherwise return "invalid".

// Inputs:
// A string.
// Output:
// "valid" if the string meets the criteria, otherwise "invalid".
// Example:
// string = "aabbcc"

// Output: valid

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Day4Question2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        sc.close();
        String result = isValidString(str);
        System.out.println(result);
    }

    public static String isValidString(String str) {
        Map<Character, Integer> charFrequency = new HashMap<>();
        for (char c : str.toCharArray()) {
            charFrequency.put(c, charFrequency.getOrDefault(c, 0) + 1);
        }

        Map<Integer, Integer> frequencyCount = new HashMap<>();
        for (int frequency : charFrequency.values()) {
            frequencyCount.put(frequency, frequencyCount.getOrDefault(frequency, 0) + 1);
        }

        if (frequencyCount.size() == 1) {
            return "valid";
        }

        if (frequencyCount.size() == 2) {
            int freq1 = 0, count1 = 0;
            int freq2 = 0, count2 = 0;
            int index = 0;
            for (Map.Entry<Integer, Integer> entry : frequencyCount.entrySet()) {
                if (index == 0) {
                    freq1 = entry.getKey();
                    count1 = entry.getValue();
                } else {
                    freq2 = entry.getKey();
                    count2 = entry.getValue();
                }
                index++;
            }

            if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
                return "valid";
            }
            if ((freq1 == freq2 + 1 && count1 == 1) || (freq2 == freq1 + 1 && count2 == 1)) {
                return "valid";
            }
        }

        return "invalid";
    }
}
