import java.util.LinkedList;
import java.util.Queue;
public class Day10_ques1{
   public static void reverseQueue(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            return;
        }
        int front = queue.poll();

        reverseQueue(queue);

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
