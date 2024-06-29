import java.util.Scanner;
import java.util.Stack;

public class EqualStackHeight {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the number of cylinders in stack 1:");
            int n1 = scanner.nextInt();
            int[] stack1 = new int[n1];
            System.out.print("Enter the heights of the cylinders in stack 1:");
            for (int i = 0; i < n1; i++) {
                stack1[i] = scanner.nextInt();
            }

            System.out.print("Enter the number of cylinders in stack 2:");
            int n2 = scanner.nextInt();
            int[] stack2 = new int[n2];
            System.out.print("Enter the heights of the cylinders in stack 2:");
            for (int i = 0; i < n2; i++) {
                stack2[i] = scanner.nextInt();
            }

            System.out.print("Enter the number of cylinders in stack 3:");
            int n3 = scanner.nextInt();
            int[] stack3 = new int[n3];
            System.out.print("Enter the heights of the cylinders in stack 3:");
            for (int i = 0; i < n3; i++) {
                stack3[i] = scanner.nextInt();
            }

            System.out.print(
                    "The maximum possible height where all stacks are equal: "
                            + maxEqualHeight(stack1, stack2, stack3));
        }
    }

    public static int maxEqualHeight(int[] stack1, int[] stack2, int[] stack3) {
        Stack<Integer> s1 = convertArrayToStack(stack1);
        Stack<Integer> s2 = convertArrayToStack(stack2);
        Stack<Integer> s3 = convertArrayToStack(stack3);

        int h1 = getHeight(s1);
        int h2 = getHeight(s2);
        int h3 = getHeight(s3);

        while (true) {
            if (s1.isEmpty() || s2.isEmpty() || s3.isEmpty()) {
                return 0;
            }

            if (h1 == h2 && h2 == h3) {
                return h1;
            }

            if (h1 >= h2 && h1 >= h3) {
                h1 -= s1.pop();
            } else if (h2 >= h1 && h2 >= h3) {
                h2 -= s2.pop();
            } else if (h3 >= h1 && h3 >= h2) {
                h3 -= s3.pop();
            }
        }
    }

    private static Stack<Integer> convertArrayToStack(int[] array) {
        Stack<Integer> stack = new Stack<>();
        for (int i = array.length - 1; i >= 0; i--) {
            stack.push(array[i]);
        }
        return stack;
    }

    private static int getHeight(Stack<Integer> stack) {
        int height = 0;
        for (int value : stack) {
            height += value;
        }
        return height;
    }
}
