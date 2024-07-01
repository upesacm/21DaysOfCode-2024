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
            return -1;
        }
        int top = stack.pop();
        if (top == maxStack.peek()) {
            maxStack.pop();
        }
        return top;
    }

    public int getMax() {
        if (maxStack.isEmpty()) {
            return -1;  // or throw an exception
        }
        return maxStack.peek();
    }

    public static void main(String[] args) {
        MaxStack stack = new MaxStack();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.getMax());
        stack.pop();
        System.out.println(stack.getMax());
    }
}
