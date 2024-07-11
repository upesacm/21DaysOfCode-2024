import java.util.Scanner;

public class Day4_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter string: ");
        String input = scanner.nextLine();
        scanner.close();

        int[] count = new int[26]; 

        for (int i = 0; i < input.length(); i++) {
            char c = Character.toLowerCase(input.charAt(i));
            if (c >= 'a' && c <= 'z') { 
                count[c - 'a']++; 
            }
        }

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0 && count[i] < min) {
                min = count[i];
            }
        }

        int diffCount = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0 && count[i] != min) {
                if (count[i] - 1 == min) {
                    diffCount++;
                } else {
                    System.out.println("invalid");
                    return;
                }
            }
        }

        if (diffCount <= 1) {
            System.out.println("valid");
        } else {
            System.out.println("invalid");
        }
    }
}
