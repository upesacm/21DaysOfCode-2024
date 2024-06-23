//Question-2
//Author - Ayush Dey

import java.util.Scanner;

public class Q2 {

    // The Function to check if a string is symmetrical
    static boolean isSymmetrical(String str) {
        char[] chars = str.toCharArray();
        int n = chars.length;

        for (int i = 0; i < n / 2; i++) {
            if (chars[i] != chars[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        scanner.close();

        boolean result = isSymmetrical(input);

        if (result) {
            System.out.println("symmetrical");
        } else {
            System.out.println("not symmetrical");
        }
    }
}


