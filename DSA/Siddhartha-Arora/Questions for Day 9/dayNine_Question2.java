/***Question 2:**  Check if a given string of brackets is balanced. The brackets include (), {}, and [].
##### Inputs:
- A string consisting of bracket characters.
##### Output:
-	"YES" if the brackets are balanced, otherwise "NO".
##### Example:
string = "{[()]}"

Output: YES

 */
import java.util.Stack;

public class dayNine_Question2 {
    public static String isBalanced(String brackets) {
        Stack<Character> stack = new Stack<>();
        
        for (char ch : brackets.toCharArray()) {
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
    
}