import java.util.Scanner;

public class Day2_Solution1 {

    public static String isClassCancelled(int threshold, int[] arrivalTimes) {
        int onTimeCount = 0;

        // Count the number of students who arrived on time
        for (int time : arrivalTimes) {
            if (time <= 0) {
                onTimeCount++;
            }
        }

        // Compare the count with the threshold
        if (onTimeCount < threshold) {
            return "YES";
        } else {
            return "NO";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input threshold
        System.out.print("Enter the threshold number of students: ");
        int threshold = scanner.nextInt();

        // Input number of students
        System.out.print("Enter the number of students: ");
        int numberOfStudents = scanner.nextInt();

        // Input arrival times
        int[] arrivalTimes = new int[numberOfStudents];
        System.out.println("Enter the arrival times of the students: ");
        for (int i = 0; i < numberOfStudents; i++) {
            arrivalTimes[i] = scanner.nextInt();
        }

        // Close the scanner
        scanner.close();

        // Determine if the class is cancelled and print the result
        System.out.println(isClassCancelled(threshold, arrivalTimes));
    }
}
