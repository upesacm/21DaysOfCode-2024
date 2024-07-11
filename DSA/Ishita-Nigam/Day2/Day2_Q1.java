import java.util.Scanner;

public class Day2_Q1 {
    public static String isClassCancelled(int threshold, int[] arrivalTimes) {
        int onTimeCount = 0;
        for (int time : arrivalTimes) {
            if (time <= 0) {
                onTimeCount++;
            }
        }
        return onTimeCount < threshold ? "YES" : "NO";
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter the threshold number of students:");
        int threshold = in.nextInt();

        System.out.println("Enter the arrival times of students (space-separated):");
        String[] input = in.next().split(" ");
        int[] arrivalTimes = new int[input.length];

        for (int i = 0; i < input.length; i++) {
            arrivalTimes[i] = Integer.parseInt(input[i]);
        }

        String result = isClassCancelled(threshold, arrivalTimes);
        System.out.println("Output: " + result);

        in.close();
    }
}
