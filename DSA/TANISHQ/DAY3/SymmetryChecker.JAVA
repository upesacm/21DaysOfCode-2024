public class SymmetryChecker {

    public static String checkSymmetry(String str) {
        // Convert the string to a character array
        char[] chars = str.toCharArray();
        
        // Reverse the character array
        for (int i = 0; i < chars.length / 2; i++) {
            char temp = chars[i];
            chars[i] = chars[chars.length - 1 - i];
            chars[chars.length - 1 - i] = temp;
        }
        
        // Compare the reversed array with the original
        for (int i = 0; i < chars.length; i++) {
            // Convert characters to their ASCII values for comparison
            int asciiValueOriginal = (int) str.charAt(i);
            int asciiValueReversed = (int) chars[i];
            
            // Check if the ASCII values match
            if (asciiValueOriginal!= asciiValueReversed) {
                return "not symmetrical";
            }
        }
        
        return "symmetrical";
    }

    public static void main(String[] args) {
        String testString = "abcba"; // Example string
        System.out.println(checkSymmetry(testString)); // Should print "symmetrical"
    }
}
