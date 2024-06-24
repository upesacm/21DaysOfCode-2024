public class Day_3_Question_2 {
    public static String isSymmetrical(String str) {
        str = str.toLowerCase();
        str = str.replaceAll(" ", "");
        int rightptr = str.length() - 1;
        int leftptr = 0;
        while (rightptr >= 0) {
            if (Math.abs('z' - (str.charAt(rightptr) - 'a')) != str.charAt(leftptr))
                return "not symmetrical";

            --rightptr;
            ++leftptr;
        }
        return "symmetrical";
    }

    public static void main(String[] args) {
        System.out.println(isSymmetrical("ac xz"));
    }
}
