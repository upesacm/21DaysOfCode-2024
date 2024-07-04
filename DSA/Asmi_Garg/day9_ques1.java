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

    public void pop() {
        if (!stack.isEmpty()) {
            int topElement = stack.pop();
            if (topElement == maxStack.peek()) {
                maxStack.pop();
            }
        }
    }

    public int getMax() {
        if (!maxStack.isEmpty()) {
            return maxStack.peek();
        }
        throw new RuntimeException("Stack is empty");
    }

    public static void main(String[] args) {
        MaxStack stack = new MaxStack();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.getMax()); // Output: 2
        stack.pop();
        System.out.println(stack.getMax()); // Output: 1
    }
}
