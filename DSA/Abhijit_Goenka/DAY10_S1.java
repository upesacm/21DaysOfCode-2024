/*
 Write a function to reverse a queue using recursive calls.

Inputs:
A queue.
Output:
The reversed queue.
Example:
queue = [1, 2, 3]

Output: [3, 2, 1]
 */

 import java.util.LinkedList;
 import java.util.Queue;
 
 class DAY10_S1 
 {
     public static void reverse(Queue<Integer> queue) 
     {
         if (queue.isEmpty()) 
         {
             return;
         }
         
         int front = queue.poll();
         reverse(queue);
         queue.add(front);
     }
     public static void main(String[] args) 
     {
         Queue<Integer> queue = new LinkedList<>();
         queue.add(1);
         queue.add(2);
         queue.add(3);
         
         System.out.println("queue: " + queue);
         
         reverse(queue);
         
         System.out.println("Output: " + queue);
     }
 }
 