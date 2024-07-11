import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class StackUsingTwoQueues {
    private Queue<Integer> q1 = new LinkedList<>();
    private Queue<Integer> q2 = new LinkedList<>();

    public void push(int x) {
        q2.add(x);
        while (!q1.isEmpty()) {
            q2.add(q1.poll());
        }
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    public int pop() {
        if (q1.isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return q1.poll();
    }

    public int top() {
        if (q1.isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return q1.peek();
    }
}

public class Main {
    public static void main(String[] args) {
        StackUsingTwoQueues stack = new StackUsingTwoQueues();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Top");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter element to push: ");
                    int element = scanner.nextInt();
                    stack.push(element);
                    break;
                case 2:
                    int poppedElement = stack.pop();
                    if (poppedElement != -1) {
                        System.out.println("Popped element: " + poppedElement);
                    }
                    break;
                case 3:
                    int topElement = stack.top();
                    if (topElement != -1) {
                        System.out.println("Top element: " + topElement);
                    }
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
