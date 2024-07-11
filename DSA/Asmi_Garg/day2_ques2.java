import java.util.Arrays;

public class day2_ques2 {
    public static void main(String[] args) {
        int[] arr1 = { 100, 90, 90, 80 };
        int[] arr = { 70, 80, 105 };
        System.out.println(Arrays.toString(playerrank(arr, arr1)));
    }

    static int[] playerrank(int[] arr, int[] arr1) {
        int[] newarr = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 100) {
                newarr[i] = 1;
            } else {
                newarr[i] = index(arr1, arr[i]);
            }
        }
        return newarr;
    }

    static int index(int[] arr1, int traget) {
        int start = 0;
        int end = arr1.length;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (traget > arr1[mid]) {
                end = mid - 1;
            } else if (traget < arr1[mid]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return start;
    }
}