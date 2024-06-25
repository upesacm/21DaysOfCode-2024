//Question-1
//Author - Ayush Dey

import java.util.Scanner;

public class Q1 {

    // Function to check if a character is a letter
    static boolean isLetter(char ch) {
        return Character.isLetter(ch);
    }

    // Function to check if all letters (a to z) are present in the given string
    static boolean containsAllLetters(String str) {
        str = str.toLowerCase(); // Convert the string to lowercase
        boolean[] present = new boolean[26]; // Creating a boolean array to store letter presence

        for (int i = 0; i < str.length(); i++) {
            char currentChar = str.charAt(i);
            if (isLetter(currentChar)) {
                int index = currentChar - 'a'; 
                present[index] = true; 
            }
        }

        for (boolean letterPresent : present) {
            if (!letterPresent) {
                return false; 
            }
        }
        return true; 
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a sentence: ");
        String sentence = scanner.nextLine();
        scanner.close();

        if (containsAllLetters(sentence)) {
            System.out.println("complete");
        } else {
            System.out.println("incomplete");
        }
    }
}
