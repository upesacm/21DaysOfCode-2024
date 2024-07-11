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
        int threshold = 3;
        int[] arrivalTimes = {-1, -3, 4, 2};
        System.out.println(isClassCancelled(threshold, arrivalTimes));  // Output: YES
    }
}
