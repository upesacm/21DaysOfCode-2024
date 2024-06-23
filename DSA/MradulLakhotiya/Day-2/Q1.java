public class Q1 {
    public static String solution(int threshold, int[] arrival_times) {
        int on_time_students = 0;

        for (int i = 0; i < arrival_times.length; i++) {
            if (arrival_times[i] < 0) {
                on_time_students++;
            }
        }

        if (on_time_students >= threshold) {
            return "NO";
        }
        else {
            return "YES";
        }
    }
    public static void main(String[] args) {
        int threshold = 3;
        int[] arrival_times = {-1, -3, 4, 2};
        String result = Solution(threshold, arrival_times);
        System.out.println(result);
    }    
}