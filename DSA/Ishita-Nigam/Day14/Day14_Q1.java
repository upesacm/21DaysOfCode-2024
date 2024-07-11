
import java.util.Scanner;

public class Day14_Q1 {

    public static int minMoves(int[] height) {
        int n = height.length;
        int moves = 0;
        
        while (true) {
            boolean removed = false;
            for (int i = 1; i < n; i++) {
                if (height[i - 1] > height[i]) {
                    for (int j = i; j < n; j++) {
                        height[j - 1] = height[j];
                    }
                    n--;
                    removed = true;
                    break;
                }
            }
            if (!removed) {
                break;
            }
            moves++;
        }
        
        return moves;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();
        
        int[] height = new int[n];
        System.out.println("Enter the heights of the students: ");
        for (int i = 0; i < n; i++) {
            height[i] = scanner.nextInt();
        }
        
        int result = minMoves(height);
        System.out.println("Minimum number of moves: " + result);
        
        scanner.close();
    }
}
