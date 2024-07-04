import java.util.*;
import java.util.LinkedList;

class AwesomeStack {
    Queue<Integer> q1 = new LinkedList<>();
    Queue<Integer> q2 = new LinkedList<>();
    public void push(int val) {
        q2.add(val);
        while (!q1.isEmpty()) {
            q2.add(q1.peek());
            q1.remove();
        }
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    public int pop() {
        if (q1.isEmpty())
            return -1;
        return q1.remove();
    }
    public int top() {
        if (q1.isEmpty())
            return -1;
        return q1.peek();
    }
}

public class Day_8_Question_2 {
    
    public static void main(String[] args) {
        AwesomeStack stack = new AwesomeStack();
        
        stack.push(1);
        stack.push(2);
        System.out.println(stack.top());
        System.out.println(stack.pop());
        System.out.println(stack.top());
    }
}
