
// Question 1: A function to determine if a given sentence includes every letter of the English alphabet at least once. The function should be case insensitive and return "complete" if the sentence contains every letter, otherwise return "incomplete".

// Inputs:
// A string representing the sentence.
// Output:
// "complete" if the sentence is a pangram, otherwise "incomplete".
// Example:
// sentence = "The quick brown fox jumps over the lazy dog"

// Output: complete

import java.util.Scanner;

public class Day3Question1 {

    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        String sentence = sc.nextLine();
        ispangram(sentence);
    }
    public static void ispangram(String sentence) {
        sentence=sentence.toLowerCase();
        int count;
    for (char i = 'a'; i <= 'z'; i++) {
        count = 0;
            for (int j = 0; j < sentence.length(); j++) {
                if (i==(sentence.charAt(j))) {
                    count+=1;
                }}
                if (count==0) {
                    System.out.println("incomplete");
                    System.exit(0);
            
            }
        }
        System.out.println("complete");
    }
    }
