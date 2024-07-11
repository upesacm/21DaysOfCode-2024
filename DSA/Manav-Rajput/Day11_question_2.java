import java.util.ArrayList;

class PriorityQueue {
    private ArrayList<Integer> heap;

    public PriorityQueue() {
        heap = new ArrayList<>();
    }

    public void insert(int value) {
        heap.add(value);
        int currentIndex = heap.size() - 1;

        // Bubble up
        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;
            if (heap.get(currentIndex) < heap.get(parentIndex)) {
                // Swap current with parent
                int temp = heap.get(currentIndex);
                heap.set(currentIndex, heap.get(parentIndex));
                heap.set(parentIndex, temp);

                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    public int extract_min() {
        if (heap.isEmpty()) {
            throw new IllegalStateException("Priority queue is empty");
        }

        int minValue = heap.get(0);
        int lastValue = heap.remove(heap.size() - 1);

        if (!heap.isEmpty()) {
            heap.set(0, lastValue);
            int currentIndex = 0;

            // Bubble down
            while (true) {
                int leftChildIndex = 2 * currentIndex + 1;
                int rightChildIndex = 2 * currentIndex + 2;
                int smallestIndex = currentIndex;

                if (leftChildIndex < heap.size() && heap.get(leftChildIndex) < heap.get(smallestIndex)) {
                    smallestIndex = leftChildIndex;
                }

                if (rightChildIndex < heap.size() && heap.get(rightChildIndex) < heap.get(smallestIndex)) {
                    smallestIndex = rightChildIndex;
                }

                if (smallestIndex != currentIndex) {
                    // Swap current with smallest child
                    int temp = heap.get(currentIndex);
                    heap.set(currentIndex, heap.get(smallestIndex));
                    heap.set(smallestIndex, temp);

                    currentIndex = smallestIndex;
                } else {
                    break;
                }
            }
        }

        return minValue;
    }

    public static void main(String[] args) {
        PriorityQueue priorityQueue = new PriorityQueue();

        priorityQueue.insert(4);
        priorityQueue.insert(2);

        System.out.println(priorityQueue.extract_min()); // Output: 2
        System.out.println(priorityQueue.extract_min()); // Output: 4
    }
}
