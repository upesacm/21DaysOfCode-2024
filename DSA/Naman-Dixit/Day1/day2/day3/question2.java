import java.util.Scanner;

public class SymmetricalString {

  public static String isSymmetrical(String str) {
    int[] reversedAscii = new int[str.length()];
    for (int i = 0; i < str.length(); i++) {
      reversedAscii[str.length() - 1 - i] = (int) str.charAt(i);
    }

    boolean isSymmetrical = true;
    for (int i = 0; i < str.length(); i++) {
      if (reversedAscii[i] != (int) str.charAt(i)) {
        isSymmetrical = false;
        break;
      }
    }

    return isSymmetrical ? "symmetrical" : "not symmetrical";
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter a string: ");
    String userString = scanner.nextLine();

    String result = isSymmetrical(userString);
    System.out.println("The string '" + userString + "' is " + result + ".");
  }
}
