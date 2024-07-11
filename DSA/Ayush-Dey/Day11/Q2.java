// Question-2
// Author - Ayush Dey

import java.util.Scanner;

public class Q2 {
    private int[] heap;
    private int size;

    public Q2() {
        heap = new int[10]; // initial capacity
        size = 0;
    }

    public void insert(int element) {
        if (size == heap.length) {
            resize();
        }
        heap[size] = element;
        size++;
        bubbleUp(size - 1);
    }

    public int extractMin() {
        if (size == 0) {
            throw new RuntimeException("Priority queue is empty");
        }
        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        bubbleDown(0);
        return min;
    }

    private void bubbleUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] <= heap[index]) {
                break;
            }
            swap(parentIndex, index);
            index = parentIndex;
        }
    }

    private void bubbleDown(int index) {
        while (true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int smallest = index;

            if (leftChildIndex < size && heap[leftChildIndex] < heap[smallest]) {
                smallest = leftChildIndex;
            }

            if (rightChildIndex < size && heap[rightChildIndex] < heap[smallest]) {
                smallest = rightChildIndex;
            }

            if (smallest == index) {
                break;
            }

            swap(smallest, index);
            index = smallest;
        }
    }

    private void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    private void resize() {
        int[] newHeap = new int[heap.length * 2];
        System.arraycopy(heap, 0, newHeap, 0, heap.length);
        heap = newHeap;
    }

    public static void main(String[] args) {
        Q2 priorityQueue = new Q2();

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Enter 'i' to insert an element or 'e' to extract the minimum:");
            String input = scanner.next();
            if (input.equalsIgnoreCase("i")) {
                System.out.print("Enter the element to insert: ");
                int element = scanner.nextInt();
                priorityQueue.insert(element);
            } else if (input.equalsIgnoreCase("e")) {
                System.out.println("Extracted minimum: " + priorityQueue.extractMin());
            } else {
                System.out.println("Invalid input. Please enter 'i' or 'e'.");
            }
        }
    }
}