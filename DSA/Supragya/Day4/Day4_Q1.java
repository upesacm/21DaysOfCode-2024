/**
 * Question 1: Given a string, determine the number of distinct palindromic substrings of a specified length.
 * 
 * Inputs:
 * A string.
 * An integer representing the length of the substrings.
 * 
 * Output:
 * The number of distinct palindromic substrings.
 * 
 * Example:
 * string = "ababa"
 * length = 3
 * 
 * Output: 3
 */ 
import java.util.*;
public class Day4_Q1 {
    public static boolean isPalindrome(String str){
        for(int i=0;i<str.length()/2;i++){
            if(str.charAt(i)!=str.charAt(str.length()-i-1)){
                return false;
            }
        }
        return true;
    }
    public static int countPalindromes(String str, int k) {
        int count =0;
        for(int i=0;i<=str.length()-k;i++){
            if(isPalindrome(str.substring(i, i+k))){
                count++;
            }
        }
        return count;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str  = scan.nextLine();
        int k = scan.nextInt();
        System.out.println("Number of distinct palindromic substrings of length " + k + " are: " + countPalindromes(str, k));
    }
}