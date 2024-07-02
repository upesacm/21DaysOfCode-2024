import java.util.*;

class AwesomePriorityQueue {
    ArrayList<Integer> heap;
    public AwesomePriorityQueue() {
        heap = new ArrayList<Integer>();
    }
    public void insert(int val) {
        heap.add(val);
    }
    public int extractMin() {
        if (heap.isEmpty())
            return -1;
        int min = Integer.MAX_VALUE;
        for (int i: heap) {
            if (i < min)
                min = i;
        }
        heap.remove((Object) min);
        return min;
    }
}

public class Day_11_Question_2 {
    public static void main(String[] args) {
        AwesomePriorityQueue queue = new AwesomePriorityQueue();
        queue.insert(2);
        queue.insert(4);
        System.out.println(queue.extractMin());
        System.out.println(queue.extractMin());
        System.out.println(queue.extractMin());
    }
}
