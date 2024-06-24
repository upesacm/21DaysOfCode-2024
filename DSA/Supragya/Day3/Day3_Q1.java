/**
 * Question 1: 
 * A function to determine if a given sentence includes every letter of the English alphabet at least once. 
 * The function should be case insensitive and return "complete" if the sentence contains every letter, 
 * otherwise return "incomplete".
 * 
 * Inputs:
 * A string representing the sentence.
 * 
 * Output:
 * "complete" if the sentence is a pangram, otherwise "incomplete".
 * 
 * Example:
 * sentence = "The quick brown fox jumps over the lazy dog"
 * 
 * Output: complete
 */
import java.util.*;
public class Day3_Q1 {
    public static String Pangram(String str){
        HashMap<Character,Integer> map = new HashMap<>();
        str= str.toLowerCase();
        map.put(' ',0); 
        for(char i='a';i<='z';i++){
            map.put(i,0);
        }
        for(int i=0;i<str.length();i++){
            map.put(str.charAt(i),map.get(str.charAt(i))+1);
        }
        for(char i='a';i<='z';i++){
            if(map.get(i)==0){
                return "incomplete";
            }
        }
        return "complete";
    }
    public static String Pangram2(String str){
        HashSet <Character> set = new HashSet<>();
        str= str.toLowerCase();
        for(int i=0;i<str.length();i++){
            set.add(str.charAt(i));
        }
        return set.size()>=27?"complete":"incomplete";
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        System.out.println("The sentence is: " + Pangram(str));
        System.out.println("The sentence is: " + Pangram2(str));

    }
}
