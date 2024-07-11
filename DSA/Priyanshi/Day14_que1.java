import java.util.*;

public class Day14_que1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();

        int[] height = new int[n];
        System.out.println("Enter heights of students: ");
        for (int i = 0; i < n; i++) {
            height[i] = sc.nextInt();
        }
        
        // Calculate minimum moves
        int result = minimumMoves(height, n);
        
        // Output the result
        System.out.println(result);
        
        sc.close();
    }

    public static int minimumMoves(int[] height, int n) {
        int moves = 0;
        boolean sorted = false;
        
        while (!sorted) {
            sorted = true;
            List<Integer> tempList = new ArrayList<>();
            tempList.add(height[0]);
            
            for (int i = 1; i < n; i++) {
                if (height[i] >= height[i - 1]) {
                    tempList.add(height[i]);
                } else {
                    sorted = false;
                }
            }
            
            if (!sorted) {
                moves++;
                height = tempList.stream().mapToInt(i -> i).toArray();
                n = height.length;
            }
        }
        
        return moves;
    }
}
