import java.util.Scanner;

class MyStack {
    private char[] stackArray;
    private int top;
    private int capacity;

    public MyStack(int capacity) {
        this.capacity = capacity;
        this.stackArray = new char[capacity];
        this.top = -1;
    }

    public void push(char item) {
        if (top == capacity - 1) {
            System.out.println("Stack is full");
            return;
        }
        stackArray[++top] = item;
    }

    public char pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return '\0';
        }
        return stackArray[top--];
    }

    public boolean isEmpty() {
        return top == -1;
    }
}


public class Day09_29June_Ques2 {
    
    public static String checkBrackets(String str) {
        MyStack stack = new MyStack(str.length());
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == '{' || ch == '[' || ch == '(') {
                stack.push(ch);
            } 
            else if (ch == '}' || ch == ']' || ch == ')') {
                if (stack.isEmpty()) {
                    return "NO";
                }
                char top = stack.pop();
                if ((ch == '}' && top != '{') || 
                    (ch == ']' && top != '[') || 
                    (ch == ')' && top != '(')) {
                    return "NO";
                }
            }
        }
        return stack.isEmpty() ? "YES" : "NO";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter String: ");
        
        String str = scanner.nextLine();
        scanner.close();

        System.out.println(checkBrackets(str));
    }
}
