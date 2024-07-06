import java.util.Scanner;

public class Day_14_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        int size = sc.nextInt();
        int arr[][] = new int[len][2];
        for (int i=0; i < len; ++i) {
            for (int j=0; j < 2; ++j) {
                arr[i][j] = sc.nextInt();
            }
        }
        int min = arr[0][1];
        int max = arr[len-1][0];
        System.out.printf("%d ", min);
        for (int i=0; i < size; i++) {
            if (i != min && i != max)
                System.out.printf("%d ", i);
        }
        System.out.printf("%d", max);
    }
}
