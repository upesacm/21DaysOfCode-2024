public class SymmetryChecker {
    public static void main(String[] args) {
        String input = "acxz";
        System.out.println(checkSymmetry(input)); // Output: symmetrical
    }

    public static String checkSymmetry(String string) {
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        StringBuilder replacedString = new StringBuilder();

        // Replace characters based on the given rule
        for (int i = 0; i < string.length(); i++) {
            char charAtI = string.charAt(i); // Using charAt to access the character
            if (charAtI >= 'a' && charAtI <= 'z') {
                int index = charAtI - 'a'; // Calculate index in the alphabet
                char oppositeChar = alphabet.charAt(25 - index); // Get opposite character
                replacedString.append(oppositeChar);
            } else {
                // Handle non-alphabet characters (if needed)
                replacedString.append(charAtI);
            }
        }

        String reversedString = replacedString.reverse().toString();
      
        if (string.equals(reversedString)) {
            return "symmetrical";
        } else {
            return "not symmetrical";
        }
    }
}
