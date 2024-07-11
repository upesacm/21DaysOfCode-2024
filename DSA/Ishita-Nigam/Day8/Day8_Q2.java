import java.util.*;

class MyStack {
    Queue<Integer> queue1;
    Queue<Integer> queue2;

    
    public MyStack() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }
    
    
    public void push(int x) {
        queue1.offer(x);
    }
    
    
    public int pop() {
        if (queue1.isEmpty()) {
            throw new EmptyStackException();
        }
        
        while (queue1.size() > 1) {
            queue2.offer(queue1.poll());
        }
        
        int top = queue1.poll();
        
        
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
        
        return top;
    }
    
    /** Get the top element. */
    public int top() {
        if (queue1.isEmpty()) {
            throw new EmptyStackException();
        }
        
        while (queue1.size() > 1) {
            queue2.offer(queue1.poll());
        }
        
        int top = queue1.peek();
        queue2.offer(queue1.poll());
        
        // Swap queues
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
        
        return top;
    }
    
    
    public boolean empty() {
        return queue1.isEmpty();
    }
}

public class Day8_Q2 {
    public static void main(String[] args) {
        MyStack stack = new MyStack();
        
        stack.push(1);
        stack.push(2);
        System.out.println("Top element: " + stack.top()); 
        System.out.println("Popped element: " + stack.pop()); 
        System.out.println("Top element after pop: " + stack.top()); 
    }
}
