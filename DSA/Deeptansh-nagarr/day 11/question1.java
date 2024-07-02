import java.util.Scanner;

class PriorityQueue {
    private int[] heap;
    private int size;

    public PriorityQueue(int capacity) {
        heap = new int[capacity + 1];
        size = 0;
    }

    public void insert(int value) {
        if (size == heap.length - 1) {
            resize();
        }
        heap[++size] = value;
        int index = size;
        while (index > 1 && heap[index / 2] > heap[index]) {
            swap(index, index / 2);
            index = index / 2;
        }
    }

    public int extractMin() {
        if (size == 0) {
            throw new RuntimeException("Priority queue is empty");
        }
        int min = heap[1];
        heap[1] = heap[size--];
        heapify(1);
        return min;
    }

    private void resize() {
        int[] newHeap = new int[heap.length * 2];
        for (int i = 0; i < heap.length; i++) {
            newHeap[i] = heap[i];
        }
        heap = newHeap;
    }

    private void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    private void heapify(int index) {
        int smallest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right <= size && heap[right] < heap[smallest]) {
            smallest = right;
        }
      
        if (smallest!= index) {
            swap(index, smallest);
            heapify(smallest);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the capacity of the priority queue:");
        int capacity = scanner.nextInt();
        PriorityQueue priorityQueue = new PriorityQueue(capacity);
        while (true) {
            System.out.println("1. Insert element");
            System.out.println("2. Extract minimum element");
            System.out.println("3. Exit");
            System.out.println("Enter your choice:");
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Enter the element to insert:");
                    int element = scanner.nextInt();
                    priorityQueue.insert(element);
                    break;
                case 2:
                    try {
                        int min = priorityQueue.extractMin();
                        System.out.println("Extracted minimum element: " + min);
                    } catch (RuntimeException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
