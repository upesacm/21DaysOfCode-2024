
// Question - 2
// Author - Ayush Dey

import java.util.Stack;
import java.util.Scanner;

public class Q2 {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public Q2() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void enqueue(int element) {
        stack1.push(element);
    }

    public int dequeue() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }

    public static void main(String[] args) {
        Q2 queue = new Q2();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Enter 1 to enqueue, 2 to dequeue, 3 to exit:");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter element to enqueue:");
                    int element = scanner.nextInt();
                    queue.enqueue(element);
                    break;
                case 2:
                    if (!queue.stack1.isEmpty() || !queue.stack2.isEmpty()) {
                        System.out.println("Dequeued element: " + queue.dequeue());
                    } else {
                        System.out.println("Queue is empty.");
                    }
                    break;
                case 3:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}