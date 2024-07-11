public class ASCIISymmetryChecker {
    public static String checkASCIISymmetry(String str) {
        int length = str.length();
        for (int i = 0; i < length / 2; i++) {
            char front = str.charAt(i);
            char back = str.charAt(length - 1 - i);
            // Compare ASCII values
            if (front != (char)(256 - (int)back)) {
                return "not symmetrical";
            }
        }
        
        return "symmetrical";
    }
    
    public static void main(String[] args) {
        String str = "acxz";
        System.out.println(checkASCIISymmetry(str));
    }
}
