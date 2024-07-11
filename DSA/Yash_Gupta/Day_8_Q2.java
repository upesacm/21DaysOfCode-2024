//Yash gupta 500125397
public class Day_8_Q2 {
    public static void main(String args[])
    {
        //test case-1
        Queue q=new Queue(5);
        Stack s=new Stack();
        s.push(q, 1);
        s.push(q, 2);
        System.out.println(s.pop(q)); 
    }
}
class Stack{
    public void push(Queue q,int num)
    {
        q.enqueue(num);
    }
    public int pop(Queue q)
    {
        Queue temp=new Queue(q.rear+1);
        for(int i=0;i<q.rear;i++)
        {
            temp.enqueue(q.arr[0]);
            q.dequeue();
        }
        int cpy=q.arr[0];
        q.dequeue();
        for(int i=0;i<=temp.rear;i++)
        {
            q.enqueue(temp.arr[0]);
            temp.dequeue();
        }
        return cpy;
    }
    public int top(Queue q)
    {
        return q.arr[q.rear];
    }
}
class Queue{
    int arr[];
    int front;
    int rear;
    Queue(int n){
        this.front=-1;
        this.rear=-1;
        arr=new int[n];
    }
    public void enqueue(int num)
    {
        if(isFull()){return;}
        this.rear++;
        arr[rear]=num;
    }
    public void dequeue()
    {
        if(isEmpty()){return;}
        for(int i=0;i<=rear;i++)
        {
            arr[i]=arr[i+1];
        }
        this.rear--;
    }
    public boolean isEmpty()
    {
        return (rear==-1);
    }
    public boolean isFull()
    {
        return ((rear+1)==arr.length);
    }
    public void printQueue()
    {
        for(int i=0;i<=rear;i++)
        {
            System.out.println(arr[i]);
        }
    }
}
