import java.io.*;
import java.util.*;

// quiz question
public class Day_7_Question_2 {
    
    
    public static int countChar(String str, char character) {
        int count = 0;
        for (char ch: str.toCharArray()) {
            if (ch == character)
                ++count;
        }
        return count;
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        
        int min = Integer.MAX_VALUE;
        
        for (int i=0; i < str.length(); i++) {

            for (int j=str.length()-1; j > i; j--) {
                int dig0 = 0;
                int dig1 = 0;
                for (int k=0; k < i; k++) {
                    if (str.charAt(k) == 'y')
                        ++dig1;
                }
                for (int k=str.length()-1; k >= j; k--) {
                    if (str.charAt(k) == 'y')
                        ++dig1;
                }
                dig0 = countChar(str.substring(i, j), 'x');
                min = Math.min(min, Math.max(dig0, dig1));
            }
        }
        System.out.println(min);
    }
}