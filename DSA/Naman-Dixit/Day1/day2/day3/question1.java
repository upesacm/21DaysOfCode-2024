import java.util.Scanner;

public class PangramChecker {

  public static String isPangram(String sentence) {
    // Create a boolean array to track encountered letters (a-z)
    boolean[] seenLetters = new boolean[26];

    // Convert sentence to lowercase for case-insensitive check
    sentence = sentence.toLowerCase();

    // Iterate through each character
    for (char c : sentence.toCharArray()) {
      // Check if character is a lowercase letter (a-z)
      if (c >= 'a' && c <= 'z') {
        // Mark the corresponding index in seenLetters as true
        seenLetters[c - 'a'] = true;
      }
    }

    // Check if all letters have been encountered
    for (boolean seen : seenLetters) {
      if (!seen) {
        return "incomplete";
      }
    }

    return "complete";
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter a sentence: ");
    String userSentence = scanner.nextLine();

    String result = isPangram(userSentence);
    System.out.println("The sentence is " + result + ".");
  }
}
