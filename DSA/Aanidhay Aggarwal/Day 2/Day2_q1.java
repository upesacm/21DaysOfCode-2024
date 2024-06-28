import java.util.Scanner;

public class Main {
    public static String classCancelled() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the threshold number of students: ");
        int threshold = scanner.nextInt();

        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();

        int[] arrivalTimes = new int[n];
        System.out.print("Enter the arrival times (space-separated): ");
        for (int i = 0; i < n; i++) {
            arrivalTimes[i] = scanner.nextInt();
        }

        int onTimeCount = 0;
        for (int arrivalTime : arrivalTimes) {
            if (arrivalTime <= 0) {
                onTimeCount++;
            }
        }

        return (onTimeCount < threshold) ? "YES" : "NO";
    }

    public static void main(String[] args) {
        System.out.println(classCancelled());
    }
}
