
import java.util.*;

public class Day2_2 {

    public static int binarySearch(int[] scores, int a) {
        int left = 0;
        int right = scores.length - 1;
        
        while (left <= right) {
            int m = (left + right) / 2;
            if (scores[m] == a) {
                return m;
            } else if (scores[m] < a) {
                right = m - 1;
            } else {
                left = m + 1;
            }
        }
        
        return left;
    }
    
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the number of scores:");
        int n = scn.nextInt();
        System.out.println("Enter the scores of people:");
        int[] scores = new int[n];
        for(int i=0; i < n; i++){
            scores[i] = scn.nextInt();
        }
        System.out.println("Enter the number of new scores:");
        int m = scn.nextInt();
        System.out.println("Enter the new scores of people:");
        int[] player = new int[m];
        for(int j=0; j< m; j++){
            player[j] = scn.nextInt();
        }
        
        int[] ranks = new int[n];
        ranks[0] = 1;
        for (int i = 1; i < n; i++) {
            if (scores[i] == scores[i - 1]) {
                ranks[i] = ranks[i - 1];
            } else {
                ranks[i] = ranks[i - 1] + 1;
            }
        }
        
        for (int j = 0; j < m; j++) {
            int index = binarySearch(scores, player[j]);
            if (index == n) {
                System.out.println(ranks[n - 1] + 1);
            } else {
                System.out.println(ranks[index]);    
            }
        }
    }
}