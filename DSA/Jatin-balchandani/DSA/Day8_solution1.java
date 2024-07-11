import java.util.Stack;

public class Day8_solution1 {

    public static int maxEqualHeight(int[] stack1, int[] stack2, int[] stack3) {
        // Calculate initial heights of the stacks
        int height1 = 0, height2 = 0, height3 = 0;

        for (int h : stack1) height1 += h;
        for (int h : stack2) height2 += h;
        for (int h : stack3) height3 += h;

        // Pointers for the top of each stack
        int i = 0, j = 0, k = 0;

        // Iterate until one of the stacks is empty
        while (i < stack1.length && j < stack2.length && k < stack3.length) {
            // If all heights are equal, return the height
            if (height1 == height2 && height2 == height3) {
                return height1;
            }

            // Remove the top cylinder from the tallest stack
            if (height1 >= height2 && height1 >= height3) {
                height1 -= stack1[i++];
            } else if (height2 >= height1 && height2 >= height3) {
                height2 -= stack2[j++];
            } else {
                height3 -= stack3[k++];
            }
        }

        return 0; // No equal height found
    }

    public static void main(String[] args) {
        int[] stack1 = {3, 2, 1, 1, 1};
        int[] stack2 = {4, 3, 2};
        int[] stack3 = {1, 1, 4, 1};

        System.out.println(maxEqualHeight(stack1, stack2, stack3)); // Output: 5
    }
}
