/*# Questions for Day 8 – (28/06/2024)
## DSA:
**Question 1:** You have three stacks of cylinders with varying heights. Remove cylinders from the top of the stacks so that all stacks are of the same height, and return this maximum possible height.

##### Inputs:
- Three arrays of integers representing the heights of cylinders in each stack.
##### Output:
•	The maximum possible height where all stacks are equal.
##### Example:
stack1 = [3, 2, 1, 1, 1]

stack2 = [4, 3, 2]

stack3 = [1, 1, 4, 1]

##### Output: 5
 */
    import java.util.*;

public class dayEight_Question1 {

    public static void main(String[] args) {
        int[] stack1 = {3, 2, 1, 1, 1};
        int[] stack2 = {4, 3, 2};
        int[] stack3 = {1, 1, 4, 1};
        
        System.out.println(maxEqualHeight(stack1, stack2, stack3)); // Output: 5
    }

    public static int maxEqualHeight(int[] stack1, int[] stack2, int[] stack3) {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        Stack<Integer> s3 = new Stack<>();
        
        int height1 = fillStack(stack1, s1);
        int height2 = fillStack(stack2, s2);
        int height3 = fillStack(stack3, s3);

        while (!(height1 == height2 && height2 == height3)) {
            if (height1 >= height2 && height1 >= height3) {
                height1 -= s1.pop();
            } else if (height2 >= height1 && height2 >= height3) {
                height2 -= s2.pop();
            } else if (height3 >= height1 && height3 >= height2) {
                height3 -= s3.pop();
            }
        }
        
        return height1; 
    }

    private static int fillStack(int[] heights, Stack<Integer> stack) {
        int totalHeight = 0;
        for (int i = heights.length - 1; i >= 0; i--) {
            totalHeight += heights[i];
            stack.push(heights[i]);
        }
        return totalHeight;
    }
}

    

