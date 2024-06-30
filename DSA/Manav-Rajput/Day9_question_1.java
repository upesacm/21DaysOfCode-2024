public class StackUsingArray {
    private int data[];
    private int top; // topmost element of the stack
    private int maxStack[]; // stack to keep track of maximum elements
    private int maxTop; // topmost element of the max stack

    public StackUsingArray() {
        data = new int[10];
        top = -1;
        maxStack = new int[10];
        maxTop = -1;
    }

    public StackUsingArray(int capacity) {
        data = new int[capacity];
        top = -1;
        maxStack = new int[capacity];
        maxTop = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public void push(int value) {
        if (top == data.length - 1) {
            // Resize the array if needed
            int[] newData = new int[data.length * 2];
            System.arraycopy(data, 0, newData, 0, data.length);
            data = newData;
            
            // Resize the maxStack array as well
            int[] newMaxStack = new int[maxStack.length * 2];
            System.arraycopy(maxStack, 0, newMaxStack, 0, maxStack.length);
            maxStack = newMaxStack;
        }
        data[++top] = value;
        if (maxTop == -1 || value >= maxStack[maxTop]) {
            maxStack[++maxTop] = value;
        }
    }

    public int pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        int poppedValue = data[top--];
        if (poppedValue == maxStack[maxTop]) {
            maxTop--;
        }
        return poppedValue;
    }

    public int getMax() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return maxStack[maxTop];
    }

    public static void main(String[] args) {
        StackUsingArray stack = new StackUsingArray();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.getMax()); // Output: 2
        stack.pop();
        System.out.println(stack.getMax()); // Output: 1
    }
}
