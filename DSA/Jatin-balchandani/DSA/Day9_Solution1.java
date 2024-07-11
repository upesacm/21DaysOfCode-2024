import java.util.Stack;

class Day9_Solution1 {
    private Stack<Integer> mainStack;
    private Stack<Integer> maxStack;

    public Day9_Solution1() {
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
        if (mainStack.isEmpty()) return;
        int top = mainStack.pop();
        if (top == maxStack.peek()) {
            maxStack.pop();
        }
    }

    public int getMax() {
        if (maxStack.isEmpty()) return -1; // Or throw an exception
        return maxStack.peek();
    }
}
