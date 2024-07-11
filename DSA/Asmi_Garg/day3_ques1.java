import java.util.Scanner;

public class PanagramChecker {
    public static String isParagram(String sentence) {
        boolean[] letters = new boolean[26];
        int totalLetters = 0;

        sentence = sentence.toLowerCase();
        for (int i = 0; i < sentence.length(); i++) {
            char c = sentence.charAt(i);
            if (c >= 'a' && c <= 'z') {
                int index = c - 'a';
                if (!letters[index]) {
                    letters[index] = true;
                    totalLetters++;
                }
            }
        }

        if (totalLetters == 26) {
            return "complete";
        } else {
            return "incomplete";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a sentence:");
        String sentence = scanner.nextLine();

        System.out.println(isParagram(sentence));
        scanner.close();
    }
}
