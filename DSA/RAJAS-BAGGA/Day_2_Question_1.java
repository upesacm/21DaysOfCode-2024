public class Day_2_Question_1 {
    public static String isClassCanceled(int times[], int threshold) {
        for (int i=0; i < times.length; i++) {
            if (times[i] < 0)
                --threshold;
            if (threshold <= 0)
                return "NO";
        }
        return "YES";
    }
    public static void main(String[] args) {
        int []arr = {-1, -3, 4, 2, -10};
        System.out.println(isClassCanceled(arr, 3));
    }
}
