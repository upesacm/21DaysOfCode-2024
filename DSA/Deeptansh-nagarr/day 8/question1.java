import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the heights of cylinders in stack 1 (separated by space):");
        String[] stack1Input = scanner.nextLine().split(" ");
        int[] stack1 = new int[stack1Input.length];
        for (int i = 0; i < stack1Input.length; i++) {
            stack1[i] = Integer.parseInt(stack1Input[i]);
        }

        System.out.println("Enter the heights of cylinders in stack 2 (separated by space):");
        String[] stack2Input = scanner.nextLine().split(" ");
        int[] stack2 = new int[stack2Input.length];
        for (int i = 0; i < stack2Input.length; i++) {
            stack2[i] = Integer.parseInt(stack2Input[i]);
        }

        System.out.println("Enter the heights of cylinders in stack 3 (separated by space):");
        String[] stack3Input = scanner.nextLine().split(" ");
        int[] stack3 = new int[stack3Input.length];
        for (int i = 0; i < stack3Input.length; i++) {
            stack3[i] = Integer.parseInt(stack3Input[i]);
        }

        int total1 = 0, total2 = 0, total3 = 0;
        for (int i : stack1) total1 += i;
        for (int i : stack2) total2 += i;
        for (int i : stack3) total3 += i;

        int gcd = gcd(Math.max(Math.max(total1, total2), total3), Math.min(Math.min(total1, total2), total3));
        gcd = gcd(gcd, total1 - gcd);
        gcd = gcd(gcd, total2 - gcd);
        gcd = gcd(gcd, total3 - gcd);

        System.out.println("The maximum possible height where all stacks are equal is: " + gcd);
    }
    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
