// Question 1: Given a string, determine the number of distinct palindromic substrings of a specified length.

// Inputs:
// A string.
// An integer representing the length of the substrings.
// Output:
// The number of distinct palindromic substrings.
// Example:
// string = "ababa"

// length = 3

// Output: 3

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Day4Question1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int length = sc.nextInt();
        sc.close();  // Close the scanner after use
        int count = distinctPalindrome(str, length);
        System.out.println(count);
    }

    public static int distinctPalindrome(String str, int length) {
        Set<String> seenPalindromes = new HashSet<>();
        int palindromeCount = 0;
        
        char[] ch = str.toCharArray();
        for (int i = 0; i <= ch.length - length; i++) {
            char[] subArr = new char[length];
            for (int j = 0; j < length; j++) {
                subArr[j] = ch[i + j];
            }
            if (isPalindrome(subArr)) {
                String palindrome = new String(subArr);
                if (!seenPalindromes.contains(palindrome)) {
                    seenPalindromes.add(palindrome);
                }
                palindromeCount++;
            }
        }

        return palindromeCount;
    }

    public static boolean isPalindrome(char[] arr) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left < right) {
            if (arr[left] != arr[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
