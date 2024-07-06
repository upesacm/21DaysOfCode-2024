import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] height = new int[n];
        for (int i = 0; i < n; i++) {
            height[i] = sc.nextInt();
        }
        sc.close();
        
        if (n == 1) {
            System.out.println(0);
            return;
        }
        
        int moves = 0;
        
        while (true) {
            boolean removed = false;
            List<Integer> tempList = new ArrayList<>();
            

            tempList.add(height[0]);
            
            for (int i = 1; i < height.length; i++) {
                if (height[i] >= height[i - 1]) {
                    tempList.add(height[i]);
                } else {
                    removed = true;
                }
            }
            
            if (!removed) {
                break;
            }
            
            moves++;
            height = new int[tempList.size()];
            for (int i = 0; i < tempList.size(); i++) {
                height[i] = tempList.get(i);
            }
        }
        
        System.out.println(moves);
    }
}
