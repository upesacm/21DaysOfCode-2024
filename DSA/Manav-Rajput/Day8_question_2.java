import java.util.LinkedList;
import java.util.Queue;

public class StackUsingTwoQueues {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;

    public StackUsingTwoQueues() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    // Push element x onto stack
    public void push(int x) {
        queue1.add(x);
    }

    // Removes the element on top of the stack and returns that element
    public int pop() {
        if (queue1.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        // Move all elements except the last one from queue1 to queue2
        while (queue1.size() > 1) {
            queue2.add(queue1.remove());
        }
        // The last element of queue1 is the top element of the stack
        int topElement = queue1.remove();

        // Swap the names of the queues
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;

        return topElement;
    }

    // Get the top element
    public int top() {
        if (queue1.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        // Move all elements except the last one from queue1 to queue2
        while (queue1.size() > 1) {
            queue2.add(queue1.remove());
        }
        // The last element of queue1 is the top element of the stack
        int topElement = queue1.peek();
        queue2.add(queue1.remove());

        // Swap the names of the queues
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;

        return topElement;
    }

    // Returns whether the stack is empty
    public boolean empty() {
        return queue1.isEmpty();
    }

    public static void main(String[] args) {
        StackUsingTwoQueues stack = new StackUsingTwoQueues();
        stack.push(1);
        stack.push(2);
        System.out.println("Top element: " + stack.top()); // Output: 2
        System.out.println("Popped element: " + stack.pop()); // Output: 2
        System.out.println("Top element: " + stack.top()); // Output: 1
    }
}
