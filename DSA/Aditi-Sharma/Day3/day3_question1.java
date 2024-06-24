import java.util.*;
public class PangramChecker {

    public static String checkString(String string) {
        string = string.toLowerCase();
        String alphabets = "abcdefghijklmnopqrstuvwxyz";

        for (char letter : alphabets.toCharArray()) {
            if (!string.contains(String.valueOf(letter))) {
                return "The string is not a pangram";
            }
        }

        return "It is a pangram";
    }

    public static void main(String[] args) {
        System.out.println(checkString("The quick brown fox jumps over the lazy dog")); // It is a pangram
        System.out.println(checkString("Hello world")); // The string is not a pangram
    }
}
