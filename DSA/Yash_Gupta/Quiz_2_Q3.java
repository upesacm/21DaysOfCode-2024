import java.io.*;
import java.util.*;

public class Quiz_2_Q3 {
    public static int minBulbs(int n, int[] hallway) {
        List<int[]> bulbCoverage = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (hallway[i] != -1) {
                int x = hallway[i]; 
                int start = Math.max(0, i - x);
                int end = Math.min(n - 1, i + x);
                bulbCoverage.add(new int[]{start, end});
            }
        }
        Collections.sort(bulbCoverage, Comparator.comparingInt(a -> a[0]));

        List<int[]> mergedRanges = new ArrayList<>();
        int prevEnd = -1;
        for (int[] range : bulbCoverage) {
            if (range[0] > prevEnd) { 
                mergedRanges.add(range);
            } else if (range[1] > prevEnd) { 
                mergedRanges.get(mergedRanges.size() - 1)[1] = range[1];
            }
            prevEnd = Math.max(prevEnd, range[1]); 
        }
        Set<Integer> coveredPositions = new HashSet<>();
        for (int[] range : mergedRanges) {
            for (int pos = range[0]; pos <= range[1]; pos++) {
                coveredPositions.add(pos);
            }
        }
        if (coveredPositions.size() < n) {
            return -1;
        }
        return coveredPositions.size();
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for (int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(minBulbs(n,arr));
    }
}