import java.util.LinkedList;
import java.util.Queue;

public class ReverseQueue {

    public static void reverseQueue(Queue<Integer> q) {
        // Base case: if queue is empty, return
        if (q.isEmpty()) {
            return;
        }

        // Dequeue the front element
        int front = q.poll();

        // Reverse the remaining queue
        reverseQueue(q);

        // Enqueue the front element at the rear of the queue
        q.add(front);
    }

    // Helper function to print the queue
    public static void printQueue(Queue<Integer> q) {
        for (int elem : q) {
            System.out.print(elem + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);

        System.out.println("Original queue:");
        printQueue(queue);

        reverseQueue(queue);

        System.out.println("Reversed queue:");
        printQueue(queue);
    }
}
