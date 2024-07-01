import java.util.*;

class Day11_que2 {
    private ArrayList<Integer> heap;

    public Day11_que2() {
        heap = new ArrayList<>();
    }

    // Method to insert a new element into the heap
    public void insert(int x) {
        heap.add(x);
        siftUp(heap.size() - 1);
    }

    // Method to extract the minimum element from the heap
    public int extractMin() {
        if (heap.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }

        int min = heap.get(0);
        int lastElement = heap.remove(heap.size() - 1);
        
        if (!heap.isEmpty()) {
            heap.set(0, lastElement);
            siftDown(0);
        }
        
        return min;
    }

    // Method to sift up the element at index i
    private void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap.get(i) >= heap.get(parent)) {
                break;
            }
            swap(i, parent);
            i = parent;
        }
    }

    // Method to sift down the element at index i
    private void siftDown(int i) {
        int leftChild, rightChild, minIndex, lastIndex = heap.size() - 1;
        while ((leftChild = 2 * i + 1) <= lastIndex) {
            minIndex = leftChild;
            rightChild = leftChild + 1;
            if (rightChild <= lastIndex && heap.get(rightChild) < heap.get(leftChild)) {
                minIndex = rightChild;
            }
            if (heap.get(i) <= heap.get(minIndex)) {
                break;
            }
            swap(i, minIndex);
            i = minIndex;
        }
    }

    // Method to swap elements at indices i and j
    private void swap(int i, int j) {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    // Method to print the heap (for debugging purposes)
    public void printHeap() {
        System.out.println(heap);
    }

    public static void main(String[] args) {
        Day11_que2 priorityQueue = new Day11_que2();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Choose an operation: insert, extract_min, print, exit");
            String operation = scanner.nextLine().toLowerCase();

            switch (operation) {
                case "insert":
                    System.out.println("Enter the element to insert:");
                    int element = scanner.nextInt();
                    scanner.nextLine();  // Consume newline
                    priorityQueue.insert(element);
                    System.out.println("Element inserted: " + element);
                    break;

                case "extract_min":
                    try {
                        int minElement = priorityQueue.extractMin();
                        System.out.println("Extracted minimum element: " + minElement);
                    } catch (IllegalStateException e) {
                        System.out.println(e.getMessage());
                    }
                    break;

                case "print":
                    priorityQueue.printHeap();
                    break;

                case "exit":
                    System.out.println("Exiting.");
                    scanner.close();
                    return;

                default:
                    System.out.println("Invalid operation. Please try again.");
                    break;
            }
        }
    }
}
