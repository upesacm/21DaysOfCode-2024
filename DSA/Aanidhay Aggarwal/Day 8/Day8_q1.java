import java.util.*;

public class EqualStacks {
    public static int equalizeStacks(int[] stack1, int[] stack2, int[] stack3) {
        int height1 = Arrays.stream(stack1).sum();
        int height2 = Arrays.stream(stack2).sum();
        int height3 = Arrays.stream(stack3).sum();

        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        Stack<Integer> s3 = new Stack<>();

        for (int i = stack1.length - 1; i >= 0; i--) {
            s1.push(stack1[i]);
        }
        for (int i = stack2.length - 1; i >= 0; i--) {
            s2.push(stack2[i]);
        }
        for (int i = stack3.length - 1; i >= 0; i--) {
            s3.push(stack3[i]);
        }

        while (!(height1 == height2 && height3 == height2)) {
            if (height1 >= height2 && height1 >= height3) {
                height1 -= s1.pop();
            } else if (height2 >= height1 && height2 >= height3) {
                height2 -= s2.pop();
            } else {
                height3 -= s3.pop();
            }
        }

        return height1;
    }

    public static void main(String[] args) {
        int[] stack1 = {3, 2, 1, 1, 1};
        int[] stack2 = {4, 3, 2};
        int[] stack3 = {1, 1, 4, 1};
        
        System.out.println(equalizeStacks(stack1, stack2, stack3));
    }
}
