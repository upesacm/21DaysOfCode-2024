import java.util.Stack;

public class Day10_Solution2 {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public Day10_Solution2() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    // Enqueue operation
    public void enqueue(int value) {
        stack1.push(value);
    }

    // Dequeue operation
    public int dequeue() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        if (!stack2.isEmpty()) {
            return stack2.pop();
        } else {
            throw new RuntimeException("Queue is empty");
        }
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    public static void main(String[] args) {
        Day10_Solution2 queue = new Day10_Solution2();

        queue.enqueue(1);
        queue.enqueue(2);
        System.out.println(queue.dequeue()); // Output: 1
        System.out.println(queue.dequeue()); // Output: 2
    }
}
