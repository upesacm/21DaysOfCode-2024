import java.util.HashSet;
import java.util.Set;

public class upes21daysofcodeACM {
    
    public static String isPangram(String sentence) {
        sentence = sentence.toLowerCase();
        Set<Character> alphabet = new HashSet<>();
        for (char c = 'a'; c <= 'z'; c++) {
            alphabet.add(c);
        }
        Set<Character> lettersInSentence = new HashSet<>();
        for (char c : sentence.toCharArray()) {
            if (Character.isLetter(c)) {
                lettersInSentence.add(c);
            }
        }
        if (lettersInSentence.containsAll(alphabet)) {
            return "complete";
        } else {
            return "incomplete";
        }
    }
    
    public static void main(String[] args) {
        String sentence = "The quick brown fox jumps over the lazy dog";
        System.out.println(isPangram(sentence));
    }
}
