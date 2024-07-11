import java.util.LinkedList;
import java.util.Queue;

public class Day10_Solution1 {
    public static void reverseQueue(Queue<Integer> queue) {
        // Base case: if the queue is empty, return
        if (queue.isEmpty()) {
            return;
        }

        // Dequeue the front element
        int front = queue.poll();

        // Recursively reverse the remaining queue
        reverseQueue(queue);

        // Enqueue the front element to the back
        queue.add(front);
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);

        System.out.println("Original queue: " + queue);
        reverseQueue(queue);
        System.out.println("Reversed queue: " + queue);
    }
}
