import java.util.Stack;

public class Q1 {
    public static int solution(int[] st1, int[] st2, int[] st3) {
        Stack<Integer> stack1 = convertToStack(st1);
        Stack<Integer> stack2 = convertToStack(st2);
        Stack<Integer> stack3 = convertToStack(st3);

        int height1 = calculateHeight(st1);
        int height2 = calculateHeight(st2);
        int height3 = calculateHeight(st3);

        while (!(height1 == height2 && height2 == height3)) {
            // System.out.println(height1);
            // System.out.println(height2);
            // System.out.println(height3);

            if (height1 >= height2 && height1 >= height3) {
                height1 -= stack1.pop();
            }
            else if (height2 >= height1 && height2 >= height3) {
                height2 -= stack2.pop();
            }
            else {
                height3 -= stack3.pop();
            }
        }

        return height1;
    }

    public static Stack<Integer> convertToStack(int[] arr) {
        Stack<Integer> st = new Stack<>();

        for (int i = arr.length - 1; i >= 0; i--) {
            st.push(arr[i]);
        }

        return st;
    }

    public static int calculateHeight(int[] arr) {
        int sum = 0;

        for (int i : arr) {
            sum += i;
        }

        return sum;
    }

    public static void main(String[] args) {
        int[] stack1 = {3, 2, 1, 1, 1};
        int[] stack2 = {4, 3, 2};
        int[] stack3 = {1, 1, 4, 1};

        int result = solution(stack1, stack2, stack3);
        System.out.println(result);
    }
}
