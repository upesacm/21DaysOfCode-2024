// Question-2
// Author - Ayush Dey

import java.util.*;

public class Q2 {


    static boolean BalancedBrackets(String expr) {
        // Using ArrayDeque for stack operations
        Deque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < expr.length(); i++) {
            char x = expr.charAt(i);

            // Pushing those opening brackets onto the stack
            if (x == '(' || x == '[' || x == '{') {
                stack.push(x);
            } 
            
            else if (x == ')' || x == ']' || x == '}') {
                if (stack.isEmpty()) {
                    return false;
                }
                char check;
                switch (x) {
                    case ')':
                        check = stack.pop();
                        if (check != '(') {
                            return false;
                        }
                        break;
                    case '}':
                        check = stack.pop();
                        if (check != '{') {
                            return false;
                        }
                        break;
                    case ']':
                        check = stack.pop();
                        if (check != '[') {
                            return false;
                        }
                        break;
                }
            }
        }

        return stack.isEmpty();
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter an expression: ");
        String expr = scanner.nextLine();

        if (BalancedBrackets(expr)) {
            System.out.println("Balanced");
        } else {
            System.out.println("Not Balanced");
        }

        scanner.close();
    }
}
