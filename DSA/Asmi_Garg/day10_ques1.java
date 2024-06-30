import java.util.LinkedList;
import java.util.Queue;

public class ReverseQueue {
    
    public static void reverseQueue(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            return;
        }

        int front = queue.poll();
        reverseQueue(queue);
        queue.offer(front);
    }

    public static void printQueue(Queue<Integer> queue) {
        for (Integer element : queue) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        queue.offer(2);
        queue.offer(3);

        System.out.println("Original Queue:");
        printQueue(queue);

        reverseQueue(queue);

        System.out.println("Reversed Queue:");
        printQueue(queue);
    }
}
