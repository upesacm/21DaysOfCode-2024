/***Question 2:** Implement a stack using two queues. The stack should support standard operations like push, pop, and top.
##### Inputs/Outputs:
- Methods for stack operations.
  
Example:

stack.push(1)

stack.push(2)

stack.top()  # Output: 2

stack.pop()  # Output: 2

stack.top()  # Output: 1

*/
import java.util.*;
public class dayEight_Question2 {
    private Queue<Integer> q1;
    private Queue<Integer> q2;
    private int topElement;
    public dayEight_Question2() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }
    public void push(int x) {
        q1.add(x);
        topElement = x;
    }
    public int pop() {
        while (q1.size() > 1) {
            topElement = q1.remove();
            q2.add(topElement);
        }
        int poppedElement = q1.remove();
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
        return poppedElement;
    }
    public int top() {
        return topElement;
    }
    public boolean empty() {
        return q1.isEmpty();
    }
    public static void main(String[] args) {
        dayEight_Question2 stack = new dayEight_Question2();
        
        stack.push(1);
        stack.push(2);
        System.out.println(stack.top()); // Output: 2
        System.out.println(stack.pop()); // Output: 2
        System.out.println(stack.top()); // Output: 1
    }
    
    
}
