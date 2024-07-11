import java.util.LinkedList;
import java.util.Queue;

public class Day8_solution2 {
    private Queue<Integer> queue1 = new LinkedList<>();
    private Queue<Integer> queue2 = new LinkedList<>();

    // Push element onto stack
    public void push(int x) {
        queue1.add(x);
    }

    // Removes the element on top of the stack and returns it
    public int pop() {
        if (queue1.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }

        // Move all elements except the last to queue2
        while (queue1.size() > 1) {
            queue2.add(queue1.remove());
        }

        // Last element is the top of the stack
        int top = queue1.remove();

        // Swap the queues
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;

        return top;
    }

    // Get the top element
    public int top() {
        if (queue1.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }

        // Move all elements except the last to queue2
        while (queue1.size() > 1) {
            queue2.add(queue1.remove());
        }

        // Last element is the top of the stack
        int top = queue1.peek();
        queue2.add(queue1.remove());

        // Swap the queues
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;

        return top;
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return queue1.isEmpty();
    }

    public static void main(String[] args) {
        Day8_solution2 stack = new Day8_solution2();

        stack.push(1);
        stack.push(2);
        System.out.println(stack.top()); // Output: 2
        System.out.println(stack.pop()); // Output: 2
        System.out.println(stack.top()); // Output: 1
    }
}
