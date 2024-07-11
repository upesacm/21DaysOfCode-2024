import java.util.Stack;

public class BalancedBrackets {
    public static String isBalanced(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if (stack.isEmpty()) {
                    return "NO";
                }
                char top = stack.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return "NO";
                }
            }
        }

        return stack.isEmpty() ? "YES" : "NO";
    }

    public static void main(String[] args) {
        String string1 = "{[()]}";
        System.out.println(isBalanced(string1)); // Output: YES

        String string2 = "{[(])}";
        System.out.println(isBalanced(string2)); // Output: NO
    }
}
