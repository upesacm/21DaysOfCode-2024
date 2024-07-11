// Question - 1
// Author - Ayush Dey

import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the elements of the queue (enter 'stop' to finish):");
        while (true) {
            String input = scanner.next();
            if (input.equals("stop")) {
                break;
            }
            queue.add(Integer.parseInt(input));
        }

        System.out.println("Original queue: " + queue);
        Queue<Integer> reversedQueue = reverseQueue(queue);
        System.out.println("Reversed queue: " + reversedQueue);
    }

    public static Queue<Integer> reverseQueue(Queue<Integer> queue) {
        // Base case: If the queue is empty, return it as it is already reversed.
        if (queue.isEmpty()) {
            return queue;
        }

        // Recursive case: Removing the front element,and reversing the remaining queue, and add the removed element to the end.
        int element = queue.poll();
        Queue<Integer> reversedQueue = reverseQueue(queue);
        reversedQueue.add(element);
        return reversedQueue;
    }
}