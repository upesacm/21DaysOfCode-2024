import java.util.Stack;

public class Day10_Q2 {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public Day10_Q2() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    // Enqueue an item to the queue
    public void enqueue(int x) {
        stack1.push(x);
    }

    // Dequeue an item from the queue
    public int dequeue() {
        if (stack2.isEmpty()) {
            if (stack1.isEmpty()) {
                throw new RuntimeException("Queue is empty");
            }
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }

    public static void main(String[] args) {
        Day10_Q2 queue = new Day10_Q2();

        queue.enqueue(1);
        queue.enqueue(2);
        System.out.println("Dequeued: " + queue.dequeue()); // Output: 1
        System.out.println("Dequeued: " + queue.dequeue()); // Output: 2
    }
}
