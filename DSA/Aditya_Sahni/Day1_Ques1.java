public class que1 {
    public static void main(String[] args) {
        int[] arr = {2, 4, 1, 3};
        int day = 10;
        int month = 4;
        System.out.println(numberOfsegments(arr, day, month));
    }

    static int numberOfsegments(int[] arr, int day, int month) {
        int count = 0;

        for (int i = 0; i <= arr.length - month; i++) {
            int sum = 0;

            for (int j = i; j < i + month; j++) {
                sum += arr[j];
            }
            if (sum == day) {
                count++;
            }
        }
        
        return count;
    }
}
