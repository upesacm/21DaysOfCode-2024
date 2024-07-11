import java.util.Scanner;

public class ASCIISymmetryChecker {

    public static String isASCIISymmetrical(String input) {

        StringBuilder asciiSequence = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            asciiSequence.append((int) input.charAt(i));
        }

        String asciiString = asciiSequence.toString();

        String reversedAsciiString = asciiSequence.reverse().toString();

        if (asciiString.equals(reversedAsciiString)) {
            return "symmetrical";
        } else {
            return "not symmetrical";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string:");
        String input = scanner.nextLine();

        System.out.println(isASCIISymmetrical(input));
        scanner.close();
    }
}
