import java.util.*;

public class Main {
    public static int maxEqualHeight(int[] stack1, int[] stack2, int[] stack3) {
        int total1 = 0, total2 = 0, total3 = 0;
        for (int i : stack1) total1 += i;
        for (int i : stack2) total2 += i;
        for (int i : stack3) total3 += i;

        while (total1 != total2 || total1 != total3) {
            if (total1 >= total2 && total1 >= total3) {
                total1 -= stack1[0];
                stack1 = Arrays.copyOfRange(stack1, 1, stack1.length);
            } else if (total2 >= total1 && total2 >= total3) {
                total2 -= stack2[0];
                stack2 = Arrays.copyOfRange(stack2, 1, stack2.length);
            } else {
                total3 -= stack3[0];
                stack3 = Arrays.copyOfRange(stack3, 1, stack3.length);
            }
        }

        return total1;
    }

    public static void main(String[] args) {
        int[] stack1 = {3, 2, 1, 1, 1};
        int[] stack2 = {4, 3, 2};
        int[] stack3 = {1, 1, 4, 1};

        System.out.println(maxEqualHeight(stack1, stack2, stack3));  // Output: 5
    }
}
