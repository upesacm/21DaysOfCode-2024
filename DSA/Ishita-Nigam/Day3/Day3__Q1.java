import java.util.HashSet;
import java.util.Scanner;

public class Day3__Q1 {

    public static String isPangram(String sentence) {
        // Convert the sentence to lower case to make it case insensitive
        sentence = sentence.toLowerCase();

        // Create a HashSet to store the unique characters
        HashSet<Character> uniqueChars = new HashSet<>();

        // Iterate through each character in the sentence
        for (char c : sentence.toCharArray()) {
            // Check if the character is a letter
            if (c >= 'a' && c <= 'z') {
                // Add the character to the HashSet
                uniqueChars.add(c);
            }
        }

        // Check if the HashSet contains all 26 letters of the alphabet
        if (uniqueChars.size() == 26) {
            return "complete";
        } else {
            return "incomplete";
        }
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter a sentence
        System.out.println("Enter a sentence:");
        String sentence = scanner.nextLine();

        // Check if the sentence is a pangram and print the result
        System.out.println(isPangram(sentence));
    }
}