import java.util.Stack;

public class Day9_Q1 {

    static class MaxStack {
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
                throw new RuntimeException("Stack is empty");
            }
            int poppedElement = mainStack.pop();

            if (poppedElement == maxStack.peek()) {
                maxStack.pop();
            }
        }

        public int get_max() {
            if (maxStack.isEmpty()) {
                throw new RuntimeException("Stack is empty");
            }
            return maxStack.peek();
        }
    }

    public static void main(String[] args) {
        MaxStack stack = new MaxStack();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.get_max());
        stack.pop();
        System.out.println(stack.get_max());
    }
}
