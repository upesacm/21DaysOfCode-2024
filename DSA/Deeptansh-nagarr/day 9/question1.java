import java.util.Scanner;
import java.util.Stack;

public class MaxStack {
    private Stack<Integer> stack;
    private Stack<Integer> maxStack;

    public MaxStack() {
        stack = new Stack<>();
        maxStack = new Stack<>();
    }

    public void push(int x) {
        stack.push(x);
        if (maxStack.isEmpty() || x >= maxStack.peek()) {
            maxStack.push(x);
        }
    }

    public int pop() {
        if (stack.isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        int top = stack.pop();
        if (top == maxStack.peek()) {
            maxStack.pop();
        }
        return top;
    }

    public int getMax() {
        if (maxStack.isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return maxStack.peek();
    }

    public static void main(String[] args) {
        MaxStack maxStack = new MaxStack();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter stack operations (push x, pop, get_max). Type 'exit' to stop:");
        while (true) {
            System.out.print("Operation: ");
            String input = scanner.nextLine().trim();
            if (input.equalsIgnoreCase("exit")) {
                System.out.println("Exiting...");
                break;
            }

            String[] parts = input.split(" ");
            String operation = parts[0].toLowerCase();
            try {
                switch (operation) {
                    case "push":
                        if (parts.length != 2) {
                            System.out.println("Invalid push operation. Use 'push x' where x is an integer.");
                            continue;
                        }
                        int value = Integer.parseInt(parts[1]);
                        maxStack.push(value);
                        System.out.println("Pushed " + value);
                        break;
                    case "pop":
                        int poppedValue = maxStack.pop();
                        System.out.println("Popped " + poppedValue);
                        break;
                    case "get_max":
                        int maxValue = maxStack.getMax();
                        System.out.println("Max value: " + maxValue);
                        break;
                    default:
                        System.out.println("Invalid operation. Valid operations: push x, pop, get_max, exit.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid number format. Please enter an integer value.");
            } catch (RuntimeException e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }
}
