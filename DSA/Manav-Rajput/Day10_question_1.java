import java.util.LinkedList;
import java.util.Queue;

public class QueueReverser {

    //function to reverse the queue
    public static void reverseQueue(Queue<Integer> queue) {
        //base case
        if (queue.isEmpty()) {
            return;
        }
        //remove the front element from the queue
        int front = queue.poll();
         //recursively reverse the remaining queue
        reverseQueue(queue);
        //add the removed element to the end of the reversed queue
        queue.add(front);
    }

    public static void main(String[] args) {
        //create a queue and add some elements to it
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        //print the original queue
        System.out.println("Original queue: " + queue);
        //reverse the queue
        reverseQueue(queue);
        //print the reversed queue
        System.out.println("Reversed queue: " + queue);
    }
}
