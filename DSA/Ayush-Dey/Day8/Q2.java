// Question-2
// Author - Ayush Dey

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Q2 {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;

    public Q2() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    public void push(int value) {
        if (!queue1.isEmpty()) {
            queue1.add(value);
        } else {
            queue2.add(value);
        }
    }

    public int pop() {
        Queue<Integer> nonEmptyQueue = queue1.isEmpty() ? queue2 : queue1;
        Queue<Integer> emptyQueue = queue1.isEmpty() ? queue1 : queue2;

        while (nonEmptyQueue.size() > 1) {
            emptyQueue.add(nonEmptyQueue.poll());
        }

        return nonEmptyQueue.poll();
    }

    public int top() {
        Queue<Integer> nonEmptyQueue = queue1.isEmpty() ? queue2 : queue1;
        Queue<Integer> emptyQueue = queue1.isEmpty() ? queue1 : queue2;

        while (nonEmptyQueue.size() > 1) {
            emptyQueue.add(nonEmptyQueue.poll());
        }

        int topElement = nonEmptyQueue.poll();
        emptyQueue.add(topElement);
        return topElement;
    }

    public boolean isEmpty() {
        return queue1.isEmpty() && queue2.isEmpty();
    }

    public int size() {
        return queue1.size() + queue2.size();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Q2 stack = new Q2();

        while (true) {
            System.out.println("Choose an operation:");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Top");
            System.out.println("4. Exit");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to push: ");
                    int value = scanner.nextInt();
                    stack.push(value);
                    break;
                case 2:
                    if (!stack.isEmpty()) {
                        System.out.println("Popped value: " + stack.pop());
                    } else {
                        System.out.println("Stack is empty.");
                    }
                    break;
                case 3:
                    if (!stack.isEmpty()) {
                        System.out.println("Top value: " + stack.top());
                    } else {
                        System.out.println("Stack is empty.");
                    }
                    break;
                case 4:
                    System.out.println("Exiting.");
                    return;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
    }
}
