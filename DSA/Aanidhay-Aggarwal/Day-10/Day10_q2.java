import java.util.Scanner;
import java.util.Stack;

public class QueueUsingTwoStacks {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public QueueUsingTwoStacks() {
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
        QueueUsingTwoStacks queue = new QueueUsingTwoStacks();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of operations: ");
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter 1 to enqueue, 2 to dequeue: ");
            int operation = scanner.nextInt();
            if (operation == 1) {
                System.out.print("Enter the element to enqueue: ");
                int element = scanner.nextInt();
                queue.enqueue(element);
            } else if (operation == 2) {
                System.out.println("Dequeued element: " + queue.dequeue());
            }
        }
    }
}
