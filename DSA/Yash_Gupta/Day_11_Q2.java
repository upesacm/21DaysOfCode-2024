import java.util.*;

class PriorityQueue {
    ArrayList<Integer> heap;
    public PriorityQueue() {
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

public class Day_11_Q2 {
    public static void main(String[] args) {
        PriorityQueue queue = new PriorityQueue();
        queue.insert(2);
        queue.insert(4);
        System.out.println(queue.extractMin());
        System.out.println(queue.extractMin());
    }
}