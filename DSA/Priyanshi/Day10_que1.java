import java.util.*;

public class Day10_que1 {

    public static void reverseQueue(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            return;
        }

        int front = queue.poll();

        reverseQueue(queue);

        queue.offer(front);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.println("Enter the elements of the queue separated by spaces:");
        String[] elements = sc.nextLine().split(" ");

        for (String element : elements) {
            queue.offer(Integer.parseInt(element));
        }

        System.out.println("Original queue: " + queue);

        reverseQueue(queue);

        System.out.println("Reversed queue: " + queue);

        sc.close();
    }
}
