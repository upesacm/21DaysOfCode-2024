import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class Q2 {
    private Queue<Integer> q1 = new LinkedList<>();
    private Queue<Integer> q2 = new LinkedList<>();

    public void push(int data) {
        q1.add(data);
    }

    public int pop() throws IOException {
        if (q1.isEmpty()) {
            throw new IOException("Stack Is Empty");
        }

        while (q1.size() > 1) {
            q2.add(q1.poll());
        }

        int top_element = q2.poll();

        Queue temp = q1;
        q1 = q2;
        q2 = temp;

        return top_element;
    }

    public int top() throws IOException {
        if (q1.isEmpty()) {
            throw new IOException("Stack Is Empty");
        }

        while (q1.size() > 1) {
            q2.add(q1.poll());
        }

        int top_element = q2.peek();

        Queue temp = q1;
        q1 = q2;
        q2 = temp;

        return top_element;
    }

    public boolean isEmpty() {
        return q1.isEmpty();
    }

    public static void main(String[] args) {
        Q2 stack = new Q2();

        stack.push(1);
        stack.push(2);
        try {
            System.out.println(stack.top()); // Output: 2
            System.out.println(stack.pop()); // Output: 2
            System.out.println(stack.top()); // Output: 1
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
}