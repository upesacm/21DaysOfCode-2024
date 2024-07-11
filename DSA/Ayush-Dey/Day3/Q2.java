<<<<<<< HEAD
//Question-2
//Author - Ayush Dey

import java.util.Scanner;

public class Q2 {

    public static String reverseAlphabet(String input) {
        StringBuilder reversedString = new StringBuilder();

        for (char c : input.toCharArray()) {
            if (Character.isLetter(c)) {
                char reverseChar = (char) ('a' + ('z' - Character.toLowerCase(c)));
                reversedString.append(reverseChar);
            }
        }

        return reversedString.toString();
    }

    // Function to check if the string is symmetrical based on the reversed alphabet
    public static String isSymmetrical(String input) {
        // Stripping non-letter characters and whitespace
        String strippedInput = input.replaceAll("[^a-zA-Z]", "").toLowerCase();

        String reversedAlphabetString = reverseAlphabet(strippedInput);
        
        // Reversing the reversed alphabet string
        String finalReversedString = new StringBuilder(reversedAlphabetString).reverse().toString();

        // Checking if the stripped input string is the same as the final reversed string
        if (strippedInput.equals(finalReversedString)) {
            return "symmetrical";
        } else {
            return "not symmetrical";
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string:");
        String userInput = scanner.nextLine();

        String result = isSymmetrical(userInput);
        System.out.println(result);
        scanner.close();
    }
}
=======
//Question-2
//Author - Ayush Dey

import java.util.Scanner;

public class Q2 {

    public static String reverseAlphabet(String input) {
        StringBuilder reversedString = new StringBuilder();

        for (char c : input.toCharArray()) {
            if (Character.isLetter(c)) {
                char reverseChar = (char) ('a' + ('z' - Character.toLowerCase(c)));
                reversedString.append(reverseChar);
            }
        }

        return reversedString.toString();
    }

    // Function to check if the string is symmetrical based on the reversed alphabet
    public static String isSymmetrical(String input) {
        // Stripping non-letter characters and whitespace
        String strippedInput = input.replaceAll("[^a-zA-Z]", "").toLowerCase();

        String reversedAlphabetString = reverseAlphabet(strippedInput);
        
        // Reversing the reversed alphabet string
        String finalReversedString = new StringBuilder(reversedAlphabetString).reverse().toString();

        // Checking if the stripped input string is the same as the final reversed string
        if (strippedInput.equals(finalReversedString)) {
            return "symmetrical";
        } else {
            return "not symmetrical";
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string:");
        String userInput = scanner.nextLine();

        String result = isSymmetrical(userInput);
        System.out.println(result);
        scanner.close();
    }
}
>>>>>>> 5893df8d1fa391f333f250221b578ac352a537b9
