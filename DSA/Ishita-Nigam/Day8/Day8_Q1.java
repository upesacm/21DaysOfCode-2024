public class Day8_Q1 {

    public static void main(String[] args) {
        int[] stack1 = { 3, 2, 1, 1, 1 };
        int[] stack2 = { 4, 3, 2 };
        int[] stack3 = { 1, 1, 4, 1 };

        int maxEqualHeight = equalizeHeight(stack1, stack2, stack3);
        System.out.println("Maximum possible equal height: " + maxEqualHeight);
    }

    public static int equalizeHeight(int[] stack1, int[] stack2, int[] stack3) {
        int sum1 = calculateTotalHeight(stack1);
        int sum2 = calculateTotalHeight(stack2);
        int sum3 = calculateTotalHeight(stack3);

        int top1 = 0, top2 = 0, top3 = 0;

        while (!(sum1 == sum2 && sum2 == sum3)) {
            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= stack1[top1++];
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= stack2[top2++];
            } else if (sum3 >= sum1 && sum3 >= sum2) {
                sum3 -= stack3[top3++];
            }
        }

        return sum1;
    }

    public static int calculateTotalHeight(int[] stack) {
        int sum = 0;
        for (int height : stack) {
            sum += height;
        }
        return sum;
    }
}
