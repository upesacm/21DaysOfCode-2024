import java.util.Scanner;

public class PangramChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a sentence: ");
        String sentence = scanner.nextLine();

        boolean isPangram = true;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!sentence.toLowerCase().contains(String.valueOf(c))) {
                isPangram = false;
                break;
            }
        }

        System.out.println(isPangram ? "complete" : "incomplete");
    }
}
