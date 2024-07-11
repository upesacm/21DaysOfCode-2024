import java.util.ArrayList;
import java.util.PriorityQueue;

public class Q2 {
    private ArrayList<Integer> heap;

    public Q2() {
        heap = new ArrayList<>();
    }

    public void insert(int data) {
        heap.add(data);
        heapifyUp(heap.size() - 1);
    }

    public int extractMin() {
        if (heap.size() == 0) {
            throw new IllegalStateException("Queue Is Empty");
        }

        int min_value = heap.get(0);
        int last_value = heap.remove(heap.size() - 1);

        if (heap.size() != 0) {
            heap.set(0, last_value);
            heapifyDown(0);
        }

        return min_value;

        
    }

    public void heapifyUp(int index) {
        while (index > 0) {
            int parent_index = (index - 1) / 2;

            if (heap.get(index) >= heap.get(parent_index)) {
                break;
            }
            swap(index, parent_index);
            index = parent_index;
        }
    }

    public void heapifyDown(int index) {
        int size = heap.size();

        while (index < size) {
            int l_child = index * 2 + 1;
            int r_child = index * 2 + 2;
            int smallest = index;

            if (l_child < size && heap.get(l_child) < heap.get(index)) {
                smallest = l_child;
            }
            if (r_child < size && heap.get(r_child) < heap.get(l_child)) {
                smallest = r_child;
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
        Q2 priorityQueue = new Q2();

        priorityQueue.insert(4);
        priorityQueue.insert(2);
        priorityQueue.insert(5);
        priorityQueue.insert(1);

        System.out.println(priorityQueue.extractMin());
        System.out.println(priorityQueue.extractMin());
        System.out.println(priorityQueue.extractMin());
        System.out.println(priorityQueue.extractMin());
    }
} 