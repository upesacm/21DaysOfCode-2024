/*
 A function to determine if a given sentence includes every letter of the English alphabet at least once. The function should be case insensitive and return "complete" if the sentence contains every letter, otherwise return "incomplete".

Inputs:
A string representing the sentence.
Output:
"complete" if the sentence is a pangram, otherwise "incomplete".
Example:
sentence = "The quick brown fox jumps over the lazy dog"

Output: complete
 */
import java.util.*;
class DAY3_S1 
{

    public static String AllCharacter(String sent) {
        sent = sent.toLowerCase();
        boolean[] foundLetters = new boolean[26];
        int uniqueLetterCount = 0;

        for (char c : sent.toCharArray()) 
        {
            if (c >= 'a' && c <= 'z') 
            {
                int index = c - 'a';
                if (!foundLetters[index]) 
                {
                    foundLetters[index] = true;
                    uniqueLetterCount++;
                }
            }
        }
        if (uniqueLetterCount == 26) 
        {
            return "complete";
        }
        else 
        {
            return "incomplete";
        }
    }

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        String sentence1 = sc.nextLine();
        System.out.println(AllCharacter(sentence1));  // Output: complete

        
    }
}
