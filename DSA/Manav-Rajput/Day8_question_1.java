import java.util.*;

public class EqualStackHeight {
    public static void main(String[] args) {
        List<Integer> stack1 = Arrays.asList(3, 2, 1, 1, 1);
        List<Integer> stack2 = Arrays.asList(4, 3, 2);
        List<Integer> stack3 = Arrays.asList(1, 1, 4, 1);

        System.out.println("Maximum possible height where all stacks are equal: " + maxEqualHeight(stack1, stack2, stack3));
    }

    public static int maxEqualHeight(List<Integer> stack1, List<Integer> stack2, List<Integer> stack3) {
        int height1 = stackHeight(stack1);
        int height2 = stackHeight(stack2);
        int height3 = stackHeight(stack3);

        int index1 = 0, index2 = 0, index3 = 0;

        while (true) {
            // If any stack is empty
            if (index1 == stack1.size() || index2 == stack2.size() || index3 == stack3.size()) {
                return 0;
            }

            // Find the current heights
            height1 = stackHeightFromIndex(stack1, index1);
            height2 = stackHeightFromIndex(stack2, index2);
            height3 = stackHeightFromIndex(stack3, index3);

            // If all heights are equal
            if (height1 == height2 && height2 == height3) {
                return height1;
            }

            // Remove cylinders from the tallest stack
            if (height1 >= height2 && height1 >= height3) {
                index1++;
            } else if (height2 >= height1 && height2 >= height3) {
                index2++;
            } else {
                index3++;
            }
        }
    }

    private static int stackHeight(List<Integer> stack) {
        int height = 0;
        for (int cyl : stack) {
            height += cyl;
        }
        return height;
    }
    private static int stackHeightFromIndex(List<Integer> stack, int index) {
        int height = 0;
        for (int i = index; i < stack.size(); i++) {
            height += stack.get(i);
        }
        return height;
    }
}
