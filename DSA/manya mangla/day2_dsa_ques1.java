public class ClassCancellation {

    public static String shouldCancelClass(int threshold, int[] arrivalTimes) {
        int onTimeCount = 0;
        
        // Count number of on-time arrivals
        for (int time : arrivalTimes) {
            if (time <= 0) {  // non-positive indicates on-time
                onTimeCount++;
            }
        }
        
        // Determine if class should be cancelled
        if (onTimeCount < threshold) {
            return "YES";
        } else {
            return "NO";
        }
    }

    public static void main(String[] args) {
        int threshold = 3;
        int[] arrivalTimes = {-1, -3, 4, 2};
        
        // Output: YES
        System.out.println(shouldCancelClass(threshold, arrivalTimes));
    }
}
