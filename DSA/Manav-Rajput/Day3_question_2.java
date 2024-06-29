public class SymmetricalChecker {
    public static String checkSymmetry(String str) {
        String mirrorChars = "zyxwvutsrqponmlkjihgfedcba";
        StringBuilder reversedStr = new StringBuilder();
        for (char c : str.toCharArray()) {
            int index = "abcdefghijklmnopqrstuvwxyz".indexOf(c);
            if (index!= -1) {
                reversedStr.append(mirrorChars.charAt(index));
            } else {
                reversedStr.append(c);
            }
        }

    
        return str.equals(reversedStr.reverse().toString())? "symmetrical" : "not symmetrical";
    }

    public static void main(String[] args) {
        String str = "acxz";
        System.out.println(checkSymmetry(str)); 
    }
}
