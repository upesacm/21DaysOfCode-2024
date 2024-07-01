//Yash Gupta 500125397
public class Day_10_Q1 {
    public static void reverseQueue(Queue queue)
    {
        if (queue.isEmpty()) {
            return;
        }
        int front = queue.dequeue();
        reverseQueue(queue);
        queue.enqueue(front);
    }
    public static void main(String[] args) {
        Queue queue=new Queue(5);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);
        reverseQueue(queue);
        for(int i=0;i<=queue.rear;i++)
        {
            System.out.println(queue.arr[i]);
        }
    }
}

class Queue{
    int rear;
    int arr[];
    Queue(int size)
    {
        this.rear=-1;
        arr=new int[size];
    }
    void enqueue(int element)
    {
        this.rear++;
        this.arr[rear]=element;
    }
    int dequeue()
    {
        int temp=this.arr[0];
        for(int i=0;i<this.rear;i++)
        {
            this.arr[i]=this.arr[i+1];
        }
        this.rear--;
        return temp;
    }
    boolean isFull()
    {
        return (rear==(this.arr.length-1));
    }
    boolean isEmpty()
    {
        return this.rear==-1;
    }
}