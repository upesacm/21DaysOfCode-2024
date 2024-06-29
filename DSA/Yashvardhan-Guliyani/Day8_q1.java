import java.util.Arrays;

public class EqualStacks {
    public static int maxEqualHeight(int[] stack1, int[] stack2, int[] stack3) {
        int sum1 = Arrays.stream(stack1).sum();
        int sum2 = Arrays.stream(stack2).sum();
        int sum3 = Arrays.stream(stack3).sum();

        int i = 0, j = 0, k = 0;

        while (true) {
            if (i == stack1.length || j == stack2.length || k == stack3.length) {
                return 0;
            }
            if (sum1 == sum2 && sum2 == sum3) {
                return sum1;
            }
            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= stack1[i++];
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= stack2[j++];
            } else {
                sum3 -= stack3[k++];
            }
        }
    }

    public static void main(String[] args) {
        int[] stack1 = {1, 1, 1, 2};
        int[] stack2 = {3, 7};
        int[] stack3 = {1, 3, 1};

        int result = maxEqualHeight(stack1, stack2, stack3);
        System.out.println("Maximum equal height: " + result);
    }
}
