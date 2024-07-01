import java.util.Stack;

public class Q2 {
    private Stack<Integer> st1;
    private Stack<Integer> st2;

    Q2() {
        st1 = new Stack<>();
        st2 = new Stack<>();
    }

    public void enqueue(int data) {
        st1.push(data);
    }

    public int dequeue() {
        while (!st1.isEmpty()) {
            st2.push(st1.pop());
        }

        int data = st2.pop();
        
        while (!st2.isEmpty()) {
            st1.push(st2.pop());
        }

        return data;
    }

    public static void main(String[] args) {
        Q2 solution = new Q2();

        solution.enqueue(1);
        System.out.println(solution.st1);
        // System.out.println(solution.st2);
        solution.enqueue(2);

        System.out.println(solution.st1);
        // System.out.println(solution.st2);

        solution.dequeue();
        System.out.println(solution.st1);
        // System.out.println(solution.st2);
        solution.dequeue();
    }
}
