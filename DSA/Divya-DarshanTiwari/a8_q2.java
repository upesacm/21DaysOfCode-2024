import java.util.*;

public class a8_q2 {

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
            throw new RuntimeException("Stack is empty");
        }
        return q1.poll();
    }

    public int top() {
        if (q1.isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return q1.peek();
    }

    public static void main(String[] args) {
        a8_q2 stack = new a8_q2();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.top()); 
        System.out.println(stack.pop()); 
        System.out.println(stack.top()); 
    }
}