import java.util.Stack;

public class Day9_ques2 {

    public static String isBalanced(String brackets) {
        Stack<Character> stack = new Stack<>();
        
        for (char ch : brackets.toCharArray()) {
            
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            }
            
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (stack.isEmpty()) {
                    return "NO";  
                }
                char top = stack.pop();
                if (!isMatchingPair(top, ch)) {
                    return "NO"; 
                }
            }
        }
        return stack.isEmpty() ? "YES" : "NO";
    }

    private static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    public static void main(String[] args) {
        String string = "{[()]}";
        System.out.println(isBalanced(string));  
    }
}
