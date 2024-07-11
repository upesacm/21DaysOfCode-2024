import java.util.*;

public class Day8_que1 
{

    public static int equalStacks(int[] stack1, int[] stack2, int[] stack3) 
    {
        int height1 = Arrays.stream(stack1).sum();
        int height2 = Arrays.stream(stack2).sum();
        int height3 = Arrays.stream(stack3).sum();

        int i = 0, j = 0, k = 0;
        
        while (true) {
            // Find the minimum height among the three stacks
            int minHeight = Math.min(height1, Math.min(height2, height3));
        
            if (height1 == height2 && height2 == height3) {
                return height1;
            }

            if (height1 > minHeight) {
                height1 -= stack1[i++];
            }
            if (height2 > minHeight) {
                height2 -= stack2[j++];
            }
            if (height3 > minHeight) {
                height3 -= stack3[k++];
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter elements of stack 1 separated by space:");
        int[] stack1 = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        System.out.println("Enter elements of stack 2 separated by space:");
        int[] stack2 = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        System.out.println("Enter elements of stack 3 separated by space:");
        int[] stack3 = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        int result = equalStacks(stack1, stack2, stack3);
        System.out.println("The maximum possible height where all stacks are equal: " + result);

        scanner.close();
    }
}
