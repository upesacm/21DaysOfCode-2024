import java.util.Stack;
import java.util.Scanner;

public class BracketBalancer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string of brackets: ");
        String input = scanner.nextLine();
        if (isBalanced(input)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean isBalanced(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(')');
            } else if (c == '{') {
                stack.push('}');
            } else if (c == '[') {
                stack.push(']');
            } else if (stack.isEmpty() || stack.pop() != c) {
                return false;
            }
        }
        return stack.isEmpty();
    }
}
