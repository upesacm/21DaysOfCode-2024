public class Day_10_Q2 {
    public static void main(String[] args) {
        //test case-1
        Stack temp=new Stack(10);
        Queue queue=new Queue();
        queue.enqueue(temp, 1);
        queue.enqueue(temp, 2);
        queue.enqueue(temp, 3);
        queue.enqueue(temp, 4);
        System.out.println(queue.dequeue(temp));
    }
}
class Queue{
    void enqueue(Stack stack,int element)
    {
        stack.push(element);
    }   
    int dequeue(Stack stack)
    {
        Stack temp=new Stack(stack.arr.length);
        while(stack.top>0)
        {
            temp.push(stack.pop());
        }
        int val=stack.pop();
        while(temp.top!=-1)
        {
            stack.push(temp.pop());
        }
        return val;
    }
}
class Stack{
    int top;
    int arr[];
    Stack(int size)
    {
        arr=new int[size];
        top=-1;
    }
    void push(int element)
    {
        this.top++;
        this.arr[top]=element;
    }
    int pop()
    {
        this.top--;
        return this.arr[top+1];
    }
}