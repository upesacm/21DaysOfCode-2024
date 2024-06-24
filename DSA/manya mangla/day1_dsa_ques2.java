public class PairCount {

    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 6, 1, 2};
        int k = 3;

        int result = countPairs(arr, k);
        System.out.println(result);  // Output: 5
    }

    public static int countPairs(int[] arr, int k) {
        int count = 0;

        // Iterate through each pair (i, j) where i < j
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                // Check if the sum of arr[i] and arr[j] is divisible by k
                if ((arr[i] + arr[j]) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
}
