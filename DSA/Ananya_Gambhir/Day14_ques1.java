import java.util.*;
public class Day14_ques1 {
    public static int minMoves(int[] heights) {
        int moves = 0;
        
        while (true) {
            boolean removed = false;
            List<Integer> tempList = new ArrayList<>();
            
            for (int i = 0; i < heights.length; i++) {
                if (i == 0 || heights[i] >= heights[i - 1]) {
                    tempList.add(heights[i]);
                } else {
                    removed = true;
                }
            }
            
            if (!removed) {
                break;
            }
            
            heights = tempList.stream().mapToInt(Integer::intValue).toArray();
            moves++;
        }
        
        return moves;
    } 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of students:");
        int n = scanner.nextInt();
        
        int[] heights = new int[n];
        System.out.println("Enter the heights of the students:");
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }
        
        System.out.println("Minimum number of moves: " + minMoves(heights));
    }
}
