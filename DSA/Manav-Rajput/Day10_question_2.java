import java.util.Stack;

public class QueueUsingStacks {

    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    //constructor to initialize the two stacks
    public QueueUsingStacks() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    //method to add an element to the queue (enqueue)
    public void enqueue(int data) {
        stack1.push(data);
    }
    //method to remove and return an element from the queue (dequeue)
    public int dequeue() {
        //if both stacks are empty, throw an exception
        if (stack1.isEmpty() && stack2.isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        //if stack2 is empty transfer all elements from stack1 to stack2
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        //return the top element from stack2
        return stack2.pop();
    }

    public static void main(String[] args) {
        //create a queue using two stacks
        QueueUsingStacks queue = new QueueUsingStacks();
        //enqueue elements into the queue
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        //dequeue elements from the queue and print them
        System.out.println(queue.dequeue()); // Output: 1
        System.out.println(queue.dequeue()); // Output: 2
        System.out.println(queue.dequeue()); // Output: 3
    }
}
