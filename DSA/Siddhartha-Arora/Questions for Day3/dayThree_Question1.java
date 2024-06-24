// package DSA.Siddhartha-Arora.Questions for Day3;
/*
 * # Questions for Day 3 - (23/06/2024)

## DSA

**Question 1:** A function to determine if a given sentence includes every letter of the English 
alphabet at least once. The function should be case insensitive and return "complete" if the 
sentence contains every letter, otherwise return "incomplete".

##### Inputs:
- A string representing the sentence.
##### Output:
- "complete" if the sentence is a pangram, otherwise "incomplete".
##### Example:
sentence = "The quick brown fox jumps over the lazy dog"
##### Output: complete

 */

 import java.util.*;

 public class dayThree_Question1 {
     public static void main(String[] args) {
         String sentence = "The quick brown fox jumps over the lazy dog";
         System.out.println(checkPangram(sentence));
     }
 
     private static String checkPangram(String str) {
         str = str.toLowerCase();
         
         Set<Character> set = new HashSet<Character>();
         
         for (char ch : str.toCharArray()) {
             if (ch >= 'a' && ch <= 'z') {
                 set.add(ch);
             }
         }
         
         return set.size() == 26 ? "complete" : "incomplete";
     }
 }
 