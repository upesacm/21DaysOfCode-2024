import java.util.LinkedList;
import java.util.Queue;

class MyStackUsingQueues {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;

    public MyStackUsingQueues() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    public void push(int x) {
        queue2.add(x);
        while (!queue1.isEmpty()) {
            queue2.add(queue1.remove());
        }
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }

    public int pop() {
        if (queue1.isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return queue1.remove();
    }

    public int top() {
        if (queue1.isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return queue1.peek();
    }

    public boolean isEmpty() {
        return queue1.isEmpty();
    }
}

public class Day08_28June_Ques2 {
    public static void main(String[] args) {
        MyStackUsingQueues stack = new MyStackUsingQueues();

        stack.push(1);
        stack.push(2);
        System.out.println(stack.top());
        System.out.println(stack.pop()); 
        System.out.println(stack.top()); 
    }
}
