/*
 Design a stack that supports push, pop, and retrieving the maximum element efficiently.

Inputs:
Operations to be performed on the stack.
Output:
Results of the operations.
Example:
stack.push(1)

stack.push(2)

stack.get_max() # Output: 2

stack.pop()

stack.get_max() # Output: 1
 */

import java.util.Stack;
import java.util.*;
class DAY9_S1 
{
    private Stack<Integer> stack;
    private Stack<Integer> maxStack;

    public DAY9_S1() 
    {
        stack = new Stack<>();
        maxStack = new Stack<>();
    }

    public void push(int x) 
    {
        stack.push(x);
        if (maxStack.isEmpty() || x >= maxStack.peek()) 
        {
            maxStack.push(x);
        }
    }

    public void pop() 
    {
        if (!stack.isEmpty()) {
            int removedElement = stack.pop();
            if (removedElement == maxStack.peek()) 
            {
                maxStack.pop();
            }
        }
    }
    public int top() 
    {
        return stack.peek();
    }
    public int getMax() 
    {
        return maxStack.peek();
    }
    public static void main(String[] args) 
    {
        DAY9_S1 stack = new DAY9_S1();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.getMax());
        stack.pop();
        System.out.println(stack.getMax()); 
    }
}
