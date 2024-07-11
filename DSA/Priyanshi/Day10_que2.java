import java.util.*;

class Day10_que2 {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public Day10_que2() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void enqueue(int x) {
        stack1.push(x);
    }

    public int dequeue() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        if (stack2.isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }

        return stack2.pop();
    }

    public int peek() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        if (stack2.isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }

        return stack2.peek();
    }

    public boolean isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    public static void main(String[] args) {
        Day10_que2 queue = new Day10_que2();
        
        queue.enqueue(1);
        queue.enqueue(2);
        System.out.println("Dequeued element: " + queue.dequeue()); // Output: 1
        System.out.println("Dequeued element: " + queue.dequeue()); // Output: 2

        queue.enqueue(3);
        queue.enqueue(4);
        System.out.println("Front element: " + queue.peek()); // Output: 3
        System.out.println("Dequeued element: " + queue.dequeue()); // Output: 3
        System.out.println("Front element: " + queue.peek()); // Output: 4
    }
}
