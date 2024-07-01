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

    public int pop() {
        if (mainStack.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        int popped = mainStack.pop();
        if (popped == maxStack.peek()) {
            maxStack.pop();
        }
        return popped;
    }

    public int getMax() {
        if (maxStack.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return maxStack.peek();
    }

    public boolean isEmpty() {
        return mainStack.isEmpty();
    }
}

public class Main {
    public static void main(String[] args) {
        MaxStack stack = new MaxStack();
        
        stack.push(1);
        stack.push(2);
        System.out.println("Max: " + stack.getMax()); 
        stack.pop();
        System.out.println("Max: " + stack.getMax()); 
    }
}
