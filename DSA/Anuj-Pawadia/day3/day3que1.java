import java.util.HashSet;

public class PangramChecker {
    public static String isPangram(String sentence) {
        // Convert the sentence to lowercase to make the function case insensitive
        sentence = sentence.toLowerCase();
        
        // Create a set to keep track of the letters of the alphabet
        HashSet<Character> letters = new HashSet<>();
        
        // Iterate through each character in the sentence
        for (char ch : sentence.toCharArray()) {
            // If the character is a letter, add it to the set
            if (ch >= 'a' && ch <= 'z') {
                letters.add(ch);
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
        // Test the function with a sample input
        String sentence1 = "The quick brown fox jumps over the lazy dog";
        String sentence2 = "Hello, world!";
        
        System.out.println(isPangram(sentence1)); // Output: complete
        System.out.println(isPangram(sentence2)); // Output: incomplete
    }
}
