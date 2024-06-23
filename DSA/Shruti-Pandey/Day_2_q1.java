public class ClassCancellation {
    public static String shouldCancelClass(int threshold, int[] arrivalTimes) {
        int onTimeStudents = 0;
        
        for (int time : arrivalTimes) {
            if (time <= 0) {
                onTimeStudents++;
            }
        }
        
        return (onTimeStudents < threshold) ? "YES" : "NO";
    }

    public static void main(String[] args) {
        int threshold = 3;
        int[] arrivalTimes = {-1, -3, 4, 2};
        
        String result = shouldCancelClass(threshold, arrivalTimes);
        System.out.println(result);
    }
}
