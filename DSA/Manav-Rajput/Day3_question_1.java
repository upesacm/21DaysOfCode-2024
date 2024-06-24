import java.util.*;

public class PangramChecker {
    public static String checkPangram(String sentence) {
        
        sentence = sentence.toLowerCase();

        HashSet<Character> letters = new HashSet<>();

        // Iterate through each character in the sentence
        for (char c : sentence.toCharArray()) {
            if (Character.isLetter(c)) {
                letters.add(c);
            }
        }

        // Check if the set contains all 26 letters of the alphabet
        if (letters.size() == 26) {
            return "complete";
        } else {
            return "incomplete";
        }
    }

    public static void main(String[] args) {
        String sentence = "The quick brown fox jumps over the lazy dog";
        System.out.println(checkPangram(sentence)); // Output: complete
    }
}
