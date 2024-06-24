/**
 * Question 2: 
 * Create a function to check if reversing the ASCII values of a string results in the same sequence when read backward. 
 * If true, return "symmetrical", otherwise return "not symmetrical".
 * 
 * Inputs:
 * A string.
 * 
 * Output:
 * "symmetrical" if the string meets the criteria, otherwise "not symmetrical".
 * 
 * Example:
 * string = "acxz"
 * 
 * Output: symmetrical
 */
import java.util.*;
public class Day3_Q2 {
    public static String isSymmetrical(String str) {
        String reciprocal = new String();
        for(int i= 0;i<str.length();i++){
            reciprocal+= (char)('z'-str.charAt(i)+'a');
        }
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)!=reciprocal.charAt(reciprocal.length()-1-i)){
                return "not symmetrical";
            }
        }
        return "symmetrical";        
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        System.out.println("The string is " + isSymmetrical(str));
    }
}