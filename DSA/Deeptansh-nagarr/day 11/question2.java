import java.util.*;

public class PriorityQueue {
    private List<Integer> heap;

    public PriorityQueue() {
        heap = new ArrayList<>();
    }

    public void insert(int value) {
        heap.add(value);
        int index = heap.size() - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap.get(parentIndex) <= heap.get(index)) {
                break;
            }
            swap(parentIndex, index);
            index = parentIndex;
        }
    }

    public int extractMin() {
        if (heap.isEmpty()) {
            throw new RuntimeException("Priority queue is empty");
        }
        int min = heap.get(0);
        heap.set(0, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        heapify(0);
        return min;
    }

    private void heapify(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap.get(left) < heap.get(smallest)) {
            smallest = left;
        }

        if (right < heap.size() && heap.get(right) < heap.get(smallest)) {
            smallest = right;
        }

        if (smallest != index) {
            swap(smallest, index);
            heapify(smallest);
        }
    }

    private void swap(int i, int j) {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    public static void main(String[] args) {
        PriorityQueue priorityQueue = new PriorityQueue();
        priorityQueue.insert(4);
        priorityQueue.insert(2);
        System.out.println(priorityQueue.extractMin());
        System.out.println(priorityQueue.extractMin());
    }
}
