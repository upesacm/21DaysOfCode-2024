import java.util.Scanner;

public class Day03_23June_Ques2{

    public static String checkSymmetry(String input) {
        input = input.toLowerCase();
        String reversed = new StringBuilder(input).reverse().toString();
        StringBuilder swapped = new StringBuilder();
        
        for (char c : reversed.toCharArray()) {
            swapped.append((char) ('z' - (c - 'a')));
        }
        return input.equals(swapped.toString()) ? "symmetrical" : "not symmetrical";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        scanner.close();

        System.out.println(checkSymmetry(input));
    }
}
