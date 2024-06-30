/*
 Check if a given string of brackets is balanced. The brackets include (), {}, and [].

Inputs:
A string consisting of bracket characters.
Output:
"YES" if the brackets are balanced, otherwise "NO".
Example:
string = "{[()]}"

Output: YES
 */
import java.util.*;
import java.util.Stack;
class DAY9_S2 
{
    public static String isBalanced(String s) 
    {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) 
        {
            if (ch == '(' || ch == '{' || ch == '[') 
            {
                stack.push(ch);
            } 
            else if (ch == ')' || ch == '}' || ch == ']') 
            {
                if (stack.isEmpty()) 
                {
                    return "NO";
                }
                char openBracket = stack.pop();
                if (!isMatchingPair(openBracket, ch)) 
                {
                    return "NO";
                }
            }
        }
        return stack.isEmpty() ? "YES" : "NO";
    }
    private static boolean isMatchingPair(char open, char close) 
    {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
    public static void main(String[] args) 
    {
        String string = "{[()]}";
        System.out.println(isBalanced(string));

    }
}
