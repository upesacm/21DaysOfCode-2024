import java.util.HashSet;
import java.util.Set;

public class PangramChecker {

    public static String checkPangram(String sentence) {
        // Convert the sentence to lowercase
        sentence = sentence.toLowerCase();
        
        // Initialize a set to keep track of unique letters
        Set<Character> letters = new HashSet<>();
        
        // Iterate through each character in the sentence
        for (int i = 0; i < sentence.length(); i++) {
            char c = sentence.charAt(i);
            // Check if the character is a letter (a-z)
            if (Character.isLetter(c)) {
                letters.add(c);
            }
            // If all 26 letters are found, no need to continue
            if (letters.size() == 26) {
                break;
            }
        }
        
        // Check if all 26 letters are in the set
        if (letters.size() == 26) {
            return "complete";
        } else {
            return "incomplete";
        }
    }

    public static void main(String[] args) {
        String sentence = "The quick brown fox jumps over the lazy dog";
        System.out.println(checkPangram(sentence));  // Output: complete
    }
}
