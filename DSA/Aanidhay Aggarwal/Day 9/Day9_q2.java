import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        System.out.println(isBalanced("{[()]}"));  // Output: YES
        System.out.println(isBalanced("([)]"));  // Output: NO
    }

    public static String isBalanced(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(')');
            } else if (c == '{') {
                stack.push('}');
            } else if (c == '[') {
                stack.push(']');
            } else if (stack.isEmpty() || stack.pop() != c) {
                return "NO";
            }
        }
        return stack.isEmpty() ? "YES" : "NO";
    }
}
