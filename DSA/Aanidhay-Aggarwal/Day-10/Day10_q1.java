import java.util.Queue;
import java.util.LinkedList;

public class Main {
    public static Queue<Integer> reverseQueue(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            return queue;
        }
        int front = queue.poll();
        queue = reverseQueue(queue);
        queue.add(front);
        return queue;
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);

        queue = reverseQueue(queue);

        System.out.println("Reversed queue: " + queue);
    }
}
