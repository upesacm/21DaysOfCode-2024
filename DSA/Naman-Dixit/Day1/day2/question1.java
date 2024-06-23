public class ClassCancellation {

    public static void main(String[] args) {
        // Example input data
        int threshold = 3;
        int[] arrivalTimes = {0, 3, -1, -5, 6, 3};

        // Determine if the class is cancelled
        String result = isClassCancelled(threshold, arrivalTimes);

        // Output result
        System.out.println(result);
    }

    public static String isClassCancelled(int threshold, int[] arrivalTimes) {
        int onTimeCount = 0;

        // Count number of students who arrived on time
        for (int time : arrivalTimes) {
            if (time <= 0) {
                onTimeCount++;
            }
        }

        // Determine if the class is cancelled
        if (onTimeCount < threshold) {
            return "YES";
        } else {
            return "NO";
        }
    }
}
