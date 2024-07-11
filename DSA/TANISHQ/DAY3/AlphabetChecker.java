public class AlphabetChecker {

    public static String checkAlphabet(String sentence) {
        // Convert the sentence to lowercase
        sentence = sentence.toLowerCase();

        // Boolean array to track presence of each letter
        boolean[] alphabetPresent = new boolean[26];

        // Iterate through each character of the sentence
        for (char c : sentence.toCharArray()) {
            // Check if the character is a letter
            if (Character.isLetter(c)) {
                // Calculate the index in the boolean array
                int index = c - 'a';
                // Mark the position as true
                alphabetPresent[index] = true;
            }
        }

        // Check if all letters are present
        for (boolean present : alphabetPresent) {
            if (!present) {
                return "incomplete";
            }
        }

        return "complete";
    }

    public static void main(String[] args) {
        String sentence = "The quick brown fox jumps over the lazy dog";
        System.out.println(checkAlphabet(sentence)); // Should print "complete"
    }
}
