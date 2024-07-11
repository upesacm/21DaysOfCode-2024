import java.util.Stack;

class AwesomeQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;
    
    public AwesomeQueue() {
        this.stack1 = new Stack<Integer>();
        this.stack2 = new Stack<Integer>();
    }
    public void enqueue(int e) {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        stack1.push(e);
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
    }
    
    public int dequeue() {
        return stack1.pop();
    }
}

public class Day_10_Question_2 {
    public static void main(String[] args) {
        AwesomeQueue queue = new AwesomeQueue();
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        
        for (int i=0; i < 4; ++i) {
            System.out.printf("%d ", queue.dequeue());
        }
    }
}
