import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class day10acm {
    public static void rev(Queue<Integer> q) {
        if (q.isEmpty())
        {
            return;
        }
        int front = q.poll();
        rev(q);
        q.add(front);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> que = new LinkedList<>();
        System.out.print("Enter the no. of elements in the queue: ");
        int n = sc.nextInt() ;
        System.out.println("Enter the elements of the queue:");
        for (int i = 0; i < n; i++) 
        {
            int val = sc.nextInt() ;
            que.add(val);
        }
        rev(que);
        System.out.print("Reversed queue is: ") ;
        while (!que.isEmpty()) {
            System.out.print(que.poll() + " ");
        }
        System.out.println() ;
    }
}
