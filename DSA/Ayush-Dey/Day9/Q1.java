// Question-1
// Author - Ayush Dey

import java.util.Scanner;
import java.util.Stack;

public class Q1 {
    private static Stack<Integer> stack;
    private static Stack<Integer> maxStack;

    public static void main(String[] args) {
        stack = new Stack<>();
        maxStack = new Stack<>();

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Get Max");
            System.out.println("4. Exit");
            System.out.print("Choose an operation: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter a number to push: ");
                    int num = scanner.nextInt();
                    push(num);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    System.out.println("Max: " + get_max());
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please choose a valid operation.");
            }
        }
    }

    private static void push(int x) {
        stack.push(x);
        if (maxStack.isEmpty() || x >= maxStack.peek()) {
            maxStack.push(x);
        } else {
            maxStack.push(maxStack.peek());
        }
    }

    private static void pop() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty. Cannot pop.");
            return;
        }
        if (maxStack.peek().equals(stack.peek())) {
            maxStack.pop();
        }
        System.out.println("Popped: " + stack.pop());
    }

    private static int get_max() {
        if (maxStack.isEmpty()) {
            System.out.println("Stack is empty. No max element.");
            return -1;
        }
        return maxStack.peek();
    }
}