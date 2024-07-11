import java.util.Stack;

import javax.management.RuntimeErrorException;

public class Q1 {

    private Stack<Integer> stack;
    private Stack<Integer> max_stack;

    Q1() {
        stack = new Stack<>();
        max_stack = new Stack<>();
    }

    public void push(int data) {
        stack.push(data);

        if (max_stack.isEmpty() || max_stack.peek() <= data) {
            max_stack.push(data);
        }
    }

    public int pop() {
        int data = stack.pop();

        if (max_stack.peek() == data) {
            max_stack.pop();
        }

        return data;
    }

    public int getMax() {
        if (stack.isEmpty()) {
            throw new RuntimeException("Stack Is Empty");
        }

        return max_stack.peek();
    }

    public static void main(String[] args) {
        Q1 maxStack = new Q1();
        maxStack.push(5);
        maxStack.push(1);
        maxStack.push(5);
        System.out.println(maxStack.getMax()); 
        maxStack.pop();
        System.out.println(maxStack.getMax()); 
        maxStack.pop();
        System.out.println(maxStack.getMax()); 
    }
}