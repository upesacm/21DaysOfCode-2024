import java.util.Scanner;

public class ClassCancellation {
    
    public static String isClassCancelled(int threshold, int[] arrivalTimes) {
        int onTimeCount = 0;
        for (int time : arrivalTimes) {
            if (time <= 0) {
                onTimeCount++;
            }
        }
        return (onTimeCount < threshold) ? "YES" : "NO";
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the threshold number of students:");
        int threshold = scanner.nextInt();
        
        System.out.println("Enter the number of students:");
        int n = scanner.nextInt();
        
        int[] arrivalTimes = new int[n];
        System.out.println("Enter the arrival times:");
        for (int i = 0; i < n; i++) {
            arrivalTimes[i] = scanner.nextInt();
        }
        
        String result = isClassCancelled(threshold, arrivalTimes);
        System.out.println(result);
    }
}

