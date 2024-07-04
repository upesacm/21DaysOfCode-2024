/*# Questions for Day 9 – (29/06/2024)
## DSA:
**Question 1:**  Design a stack that supports push, pop, and retrieving the maximum element efficiently.
##### Inputs:
- Operations to be performed on the stack.
##### Output:
-	Results of the operations.
##### Example:

stack.push(1)

stack.push(2)

stack.get_max()  # Output: 2

stack.pop()

stack.get_max()  # Output: 1

 */

 import java.util.Stack;

 public class dayNine_Question1 {
     private Stack<Integer> mainStack;
     private Stack<Integer> maxStack;
 
     public dayNine_Question1() {
         mainStack = new Stack<>();
         maxStack = new Stack<>();
     }
 
     public void push(int value) {
         mainStack.push(value);
         if (maxStack.isEmpty() || value >= maxStack.peek()) {
             maxStack.push(value);
         } else {
             maxStack.push(maxStack.peek());
         }
     }
 
     public void pop() {
         if (!mainStack.isEmpty()) {
             mainStack.pop();
             maxStack.pop();
         }
     }
 
     public int getMax() {
         if (!maxStack.isEmpty()) {
             return maxStack.peek();
         }
         throw new IllegalStateException("Stack is empty");
     }
 
 
 }
 