import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

public class Q1 {
    public static void checkPangram(String s){
        Set<Character> alphabetSet = new HashSet<>();
        for (char c = 'a'; c <= 'z'; c++) {
            alphabetSet.add(c);
        }

        // Convert the sentence to lowercase and create a set of letters in the sentence
        Set<Character> sentenceSet = new HashSet<>();
        for (char c : s.toLowerCase().toCharArray()) {
            if (Character.isLetter(c)) {
                sentenceSet.add(c);
            }
        }

        // Check if all letters in the alphabet are in the sentence
        if (sentenceSet.containsAll(alphabetSet)) {
            System.out.println("complete");
        } else {
            System.out.println("incomplete");
        }
    }
   public static void main(String[] args) {
     Scanner in=new Scanner(System.in);
     System.out.println("Enter sentence:");
     String str=in.nextLine();
     checkPangram(str.toLowerCase());
     in.close();
   } 
}
