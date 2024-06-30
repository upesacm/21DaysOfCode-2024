import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

public class Day_10_Question_1 {
    
    public static void printQueue(Queue<Integer> queue) {
        for (int i: queue) {
            System.out.printf("%d ", i);
        }
    }
    
    public static Queue<Integer> reverseQueue(Queue<Integer> queue) {
        if (queue.isEmpty())
            return queue;
        
        int save = queue.peek();
        queue.remove();
        queue = reverseQueue(queue);
        
        queue.add(save);
        return queue;
    }
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue = reverseQueue(queue);
        printQueue(queue);
    }
}
