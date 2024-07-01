import java.util.Stack;

class MaxStack {
    private Stack<Integer> mainStack;
    private Stack<Integer> maxStack;

    public MaxStack() {
        mainStack = new Stack<>();
        maxStack = new Stack<>();
    }

    public void push(int x) {
        mainStack.push(x);
        if (maxStack.isEmpty() || x >= maxStack.peek()) {
            maxStack.push(x);
        }
    }

    public void pop() {
        if (mainStack.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        int removedElement = mainStack.pop();
        if (removedElement == maxStack.peek()) {
            maxStack.pop();
        }
    }

    public int getMax() {
        if (maxStack.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return maxStack.peek();
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
