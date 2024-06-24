public class SymmetryChecker {

    public static String checkSymmetry(String str) {
        // Convert the string to character array
        char[] chars = str.toCharArray();
        
        // Arrays to store original and reversed ASCII values
        int[] originalAscii = new int[chars.length];
        int[] reversedAscii = new int[chars.length];
        
        // Populate originalAscii with ASCII values
        for (int i = 0; i < chars.length; i++) {
            originalAscii[i] = (int) chars[i];
        }
        
        // Populate reversedAscii with reversed ASCII values
        for (int i = 0; i < chars.length; i++) {
            reversedAscii[i] = originalAscii[chars.length - 1 - i];
        }
        
        // Compare originalAscii and reversedAscii
        for (int i = 0; i < chars.length; i++) {
            if (originalAscii[i] != reversedAscii[i]) {
                return "not symmetrical";
            }
        }
        
        return "symmetrical";
    }

    public static void main(String[] args) {
        String str = "acxz";
        System.out.println(checkSymmetry(str));  // Output: symmetrical
    }
}
