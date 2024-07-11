import java.util.Stack;

public class Q2 {

    public static String solution(String str) {
        Stack<Character> stack = new Stack<>();
        char[] char_arr = str.toCharArray();

        for (char ch : char_arr) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            }
            else {
                char temp = stack.peek();

                if (temp == '(' && ch == ')') {
                    stack.pop();
                }
                else if (temp == '{' && ch == '}') {
                    stack.pop();
                }
                else if (temp == '[' && ch == ']') {
                    stack.pop();
                }
                else {
                    return "NO";
                }
            }
        }

        return "YES";
    }

    public static void main(String[] args) {
        String input = "{[()]}";
        String res = solution(input);
        System.out.println(res);
    }
}
