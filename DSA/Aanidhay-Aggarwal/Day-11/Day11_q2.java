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
            throw new NoSuchElementException();
        }
        int min = heap.get(0);
        heap.set(0, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        heapifyDown();
        return min;
    }

    private void heapifyDown() {
        int index = 0;
        while (true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int smallest = index;
            if (leftChildIndex < heap.size() && heap.get(leftChildIndex) < heap.get(smallest)) {
                smallest = leftChildIndex;
            }
            if (rightChildIndex < heap.size() && heap.get(rightChildIndex) < heap.get(smallest)) {
                smallest = rightChildIndex;
            }
            if (smallest == index) {
                break;
            }
            swap(index, smallest);
            index = smallest;
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
        System.out.println(priorityQueue.extractMin()); // Output: 2
        System.out.println(priorityQueue.extractMin()); // Output: 4
    }
}
