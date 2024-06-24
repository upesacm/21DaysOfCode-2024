//Question-1
//Author: Ayush Dey

import java.util.Scanner;

public class ClassCancellation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: Threshold number of students
        System.out.print("Enter the threshold number of students: ");
        int threshold = scanner.nextInt();

        // Input: Arrival times (non-positive indicates on-time arrival)
        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();
        int[] arrivalTimes = new int[n];
        for (int i = 0; i < n; i++) {
            arrivalTimes[i] = scanner.nextInt();
        }

        boolean isCancelled = isClassCancelled(threshold, arrivalTimes);

        // Output
        System.out.println(isCancelled ? "YES" : "NO");

        scanner.close();
    }

    private static boolean isClassCancelled(int threshold, int[] arrivalTimes) {
        int onTimeCount = 0;
        for (int time : arrivalTimes) {
            if (time <= 0) {
                onTimeCount++;
            }
        }
        return onTimeCount < threshold;
    }
}
