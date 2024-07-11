import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Q1 {
    
    public static void solution(Queue<Integer> q) {
        Stack<Integer> st = new Stack<>();

        while(!q.isEmpty()) {
            st.push(q.remove());
        }

        while(!st.isEmpty()) {
            q.add(st.pop());
        }
    }

    public static void main(String[] args) {
        Queue<Integer> input = new LinkedList<>();
        input.add(1);
        input.add(2);
        input.add(3);
        System.out.println(input);
        solution(input);
        System.out.println(input);
    }
}