import java.util.LinkedList;
import java.util.Queue;
public class Day8_q1  {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;
    public Day8_q1() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }
    public void push(int x) {
        queue1.add(x);

        while (!queue2.isEmpty()) {
            queue1.add(queue2.poll());
        }
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }
    public int pop() {
        if (queue2.isEmpty()) {
            throw new RuntimeException("Pop from empty stack");
        }
        return queue2.poll();
    }
    public int top() {
        if (queue2.isEmpty()) {
            throw new RuntimeException("Top from empty stack");
        }
        return queue2.peek();
    }
    public boolean isEmpty() {
        return queue2.isEmpty();
    }
    public static void main(String[] args) {
        Day8_q1 stack = new Day8_q1();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.top());  
        System.out.println(stack.pop());  
        System.out.println(stack.top());  
    }
}
