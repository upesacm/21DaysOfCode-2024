import java.util.LinkedList;
import java.util.Queue;

class MyStack {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;
    private int topElement;

    // Constructor
    public MyStack() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    // Push element x onto stack
    public void push(int x) {
        queue1.add(x);
        topElement = x;
    }

    // Removes the element on top of the stack and returns that element
    public int pop() {
        // Move all elements except the last one from queue1 to queue2
        while (queue1.size() > 1) {
            topElement = queue1.remove();
            queue2.add(topElement);
        }
        // The last element in queue1 is the top of the stack
        int poppedElement = queue1.remove();
        
        // Swap the references of queue1 and queue2
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;

        return poppedElement;
    }

    // Get the top element
    public int top() {
        return topElement;
    }

    // Returns whether the stack is empty
    public boolean empty() {
        return queue1.isEmpty();
    }

    public static void main(String[] args) {
        MyStack stack = new MyStack();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.top()); // Output: 2
        System.out.println(stack.pop()); // Output: 2
        System.out.println(stack.top()); // Output: 1
    }
}
