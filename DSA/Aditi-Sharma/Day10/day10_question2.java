import java.util.Stack;
import java.util.*;
class DAY10_S2
{
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public DAY10_S2() 
    {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    public void enqueue(int item) 
    {
        stack1.push(item);
    }
    public int dequeue() 
    {
        if (stack2.isEmpty()) 
        {
            while (!stack1.isEmpty()) 
            {
                stack2.push(stack1.pop());
            }
        }
        
        if (stack2.isEmpty()) 
        {
            throw new RuntimeException("Queue is empty");
        }
        
        return stack2.pop();
    }

    public static void main(String[] args) 
    {
        DAY10_S2 queue = new DAY10_S2();
        queue.enqueue(1);
        queue.enqueue(2);
        System.out.println(queue.dequeue()); 
        System.out.println(queue.dequeue()); 
    }
}
