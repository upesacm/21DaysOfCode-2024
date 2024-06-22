import java.util.*;
public class Segments {

    public static int segments(int[] arr, int day, int month) {
        int parts = 0;
        for (int i = 0; i <= arr.length - month; i++) {
            int sum = 0;
            for (int j = 0; j < month; j++) {
                sum += arr[i + j];
            }
            if (sum == day) {
                parts++;
            }
        }
        return parts;
    }

     public static void main(String[] args) {
        // Test case 1: [2, 2, 1, 3, 2], day = 4, month = 2
        int[] candy1 = {2, 2, 1, 3, 2};
        int day1 = 4;
        int month1 = 2;
        System.out.println("Test case 1:");
        System.out.println("Expected output: 2");
        System.out.println("Actual output: " + segments(candy1, day1, month1));

     }
}
