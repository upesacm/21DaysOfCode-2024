import java.util.*;
public class ValidPairs {

    public static int validPairs(int[] arr, int k) {
        int count = 0;
        for (int j = 1; j < arr.length; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if ((arr[j] + arr[i]) % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 6, 1, 2};
        int k = 3;
        System.out.println(validPairs(arr, k)); 
    }
}
