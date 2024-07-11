import java.util.*;

public class Day3_1 {

    public static String String_Checker(String str) {
        boolean[] mark = new boolean[26];
        int index = 0;
        str = str.toLowerCase();

        for (int i = 0; i < str.length(); i++) {
            if ('a' <= str.charAt(i) && str.charAt(i) <= 'z') {
                index = str.charAt(i) - 'a';
                mark[index] = true;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (!mark[i]) {
                return "incomplete";
            }
        }

        return "complete";
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter a string:");
        String str = scn.nextLine();

        String result = String_Checker(str);
        System.out.println(result);
    }
}
