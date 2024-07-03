import java.util.PriorityQueue;

public class Day11_Solution2 {
    private PriorityQueue<Integer> minHeap;

    public Day11_Solution2() {
        minHeap = new PriorityQueue<>();
    }

    // Insert operation
    public void insert(int value) {
        minHeap.add(value);
    }

    // Extract-min operation
    public int extractMin() {
        if (minHeap.isEmpty()) {
            throw new RuntimeException("Priority queue is empty");
        }
        return minHeap.poll();
    }

    public static void main(String[] args) {
        Day11_Solution2 priorityQueue = new Day11_Solution2();

        priorityQueue.insert(4);
        priorityQueue.insert(2);
        System.out.println(priorityQueue.extractMin()); // Output: 2
        priorityQueue.insert(5);
        System.out.println(priorityQueue.extractMin()); // Output: 4
        System.out.println(priorityQueue.extractMin()); // Output: 5
    }
}
