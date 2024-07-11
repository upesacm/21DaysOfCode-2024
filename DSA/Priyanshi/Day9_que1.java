import java.util.*;

class Day9_que1 
{
    private Stack<Integer> stack;
    private Stack<Integer> maxStack;

    public Day9_que1() {
        stack = new Stack<>();
        maxStack = new Stack<>();
    }

    public void push(int x) {
        stack.push(x);
        if (maxStack.isEmpty() || x >= maxStack.peek()) {
            maxStack.push(x);
        }
    }

    public void pop() {
        if (stack.isEmpty()) {
            return;
        }
        int popped = stack.pop();
        if (popped == maxStack.peek()) {
            maxStack.pop();
        }
    }

    public int top() {
        if (stack.isEmpty()) {
            return -1;
        }
        return stack.peek();
    }

    public int getMax() {
        if (maxStack.isEmpty()) {
            return -1;
        }
        return maxStack.peek();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Day9_que1 stack = new Day9_que1();

        while (true) {
            System.out.println("Choose an operation: push, pop, top, get_max, exit");
            String operation = sc.nextLine().toLowerCase();

            switch (operation) {
                case "push":
                    System.out.println("Enter the element to push:");
                    int element = sc.nextInt();
                    sc.nextLine();  // Consume newline
                    stack.push(element);
                    System.out.println("Element pushed: " + element);
                    break;

                case "pop":
                    stack.pop();
                    System.out.println("Top element popped.");
                    break;

                case "top":
                    int topElement = stack.top();
                    if (topElement == -1) {
                        System.out.println("Stack is empty.");
                    } else {
                        System.out.println("Top element: " + topElement);
                    }
                    break;

                case "get_max":
                    int maxElement = stack.getMax();
                    if (maxElement == -1) {
                        System.out.println("Stack is empty.");
                    } else {
                        System.out.println("Maximum element: " + maxElement);
                    }
                    break;

                case "exit":
                    System.out.println("Exiting.");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid operation. Please try again.");
                    break;
            }
        }
    }
}
