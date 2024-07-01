import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Day10_Q1 {

    // Function to reverse the queue using recursion
    public static void reverseQueue(Queue<Integer> queue) {
        // Base case: If the queue is empty, return
        if (queue.isEmpty()) {
            return;
        }

        // Dequeue the current front item (from front)
        int front = queue.remove();

        // Reverse the remaining queue
        reverseQueue(queue);

        // Enqueue the current item (to rear)
        queue.add(front);
    }

    public static void main(String[] args) {
        // Create a queue
        Queue<Integer> queue = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);

        // Take input from the user
        System.out.println("Enter the number of elements in the queue:");
        int n = scanner.nextInt();
        System.out.println("Enter the elements of the queue:");
        for (int i = 0; i < n; i++) {
            queue.add(scanner.nextInt());
        }

        System.out.println("Original Queue: " + queue);

        // Reverse the queue
        reverseQueue(queue);

        System.out.println("Reversed Queue: " + queue);
    }
}
