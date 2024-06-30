import java.util.Stack;

public class Day_9_Question_2 {
    public static String isBalanced(String expression) {
        Stack<Character> stack = new Stack<Character>();
        
        for (char ch: expression.toCharArray()) {
            if (
                ch == '(' ||
                ch == '{' ||
                ch == '['
            ) {
                stack.push(ch);
                continue;
            }
            
            if (stack.isEmpty())
                return "NO";
            
            char check = stack.pop();
            if (ch == ')' && (check == '{' || check == '['))
                return "NO";
            else if (ch == ']' && (check == '(' || check == '{'))
                return "NO";
            else if (ch == '}' && (check == '[' || check == '('))
                return "NO";       
        }
        
        return (stack.isEmpty())? "YES": "NO";
    }
    
    public static void main(String[] args) {
        System.out.println(isBalanced("{}"));
    }
}
