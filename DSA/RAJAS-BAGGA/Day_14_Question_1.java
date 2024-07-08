import java.util.Scanner;

public class Day_14_Question_1 {
    public static void main(String[] args) {
                /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        
        for (int i=0; i < n;i++) {
          arr[i] = sc.nextInt();
        }
        int moves = 0;
        for (int i=0; i < n; i++) {
            boolean hit = false;
            int min = arr[i];
            if (arr[i] != Integer.MAX_VALUE && i != n-1) {
                for (int j=i+1; j < n; j++) {
                    if (arr[j] < min) {
                        hit = true;
                        min = arr[j];
                        arr[j] = Integer.MAX_VALUE;
                    }
                }
            }
            if (hit)
                moves++;
        }
        System.out.println(moves);
    }
}
