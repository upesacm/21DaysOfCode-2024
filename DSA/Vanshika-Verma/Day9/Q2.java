import java.util.Scanner;
import java.util.Stack;

public class Day9q1 {
    public static void main(String[] args)
     {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string of brackets:-") ;
        String input = sc.nextLine();
        if (check(input))
        {
            System.out.println("Yes");
        }
        else 
        {
            System.out.println("No") ;
        }
    }

    public static boolean check(String s)
     {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) 
        {
            if (c == '(')  {
                stack.push(')');
            } 
            else if (c == '{') {
                stack.push('}');
            } 
            else if (c == '[') {
                stack.push(']');
            } 
            else if (stack.isEmpty() || stack.pop() != c) {
                return false;
            }
        }
        return stack.isEmpty();
    }
}
