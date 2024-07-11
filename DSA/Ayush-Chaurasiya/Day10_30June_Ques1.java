class MyQueue {
    private int[] queueArray;
    private int front;
    private int rear;
    private int capacity;
    private int size;

    public MyQueue(int capacity) {
        this.capacity = capacity;
        this.queueArray = new int[capacity];
        this.front = 0;
        this.rear = -1;
        this.size = 0;
    }

    public void enqueue(int item) {
        if (isFull()) {
            System.out.println("Queue is full");
            return;
        }
        rear = (rear + 1) % capacity;
        queueArray[rear] = item;
        size++;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        int item = queueArray[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }

    public int getSize() {
        return size;
    }

    public void reverse() {
        if (isEmpty()) {
            return;
        }
        int temp = dequeue();
        reverse();
        enqueue(temp);
    }

    public void printQueue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        int currentSize = size;
        int currentFront = front;
        while (currentSize > 0) {
            System.out.print(queueArray[currentFront] + " ");
            currentFront = (currentFront + 1) % capacity;
            currentSize--;
        }
        System.out.println();
    }
}

public class Day10_30June_Ques1 {
    public static void main(String[] args) {
        MyQueue queue1 = new MyQueue(3);
        queue1.enqueue(1);
        queue1.enqueue(2);
        queue1.enqueue(3);

        System.out.println("Original Queue:");
        queue1.printQueue();

        queue1.reverse();

        System.out.println("Reversed Queue:");
        queue1.printQueue();
    }
}
