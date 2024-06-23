public class day2_ques1 {
    public static void main(String[] args) {
        int[] arrival_times = { -1, -3, 4, 2 };
        int threshold = 3;
        checkifcanceled(arrival_times, threshold);

    }

    static void checkifcanceled(int[] arr, int threshold) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 0) {
                count++;
            }
        }
        if (count >= threshold) {
            System.out.println("NO");
        } else {
            System.out.println("YES");

        }
    }
}