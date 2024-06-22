public class Day1_Q2 {

    public static int countPairs(int[] arr, int k) {
        int count = 0;

        // Iterate through each pair (i, j) where i < j
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if ((arr[i] + arr[j]) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 3, 2, 6, 1, 2 };
        int k = 3;
        int result = countPairs(arr, k);
        System.out.println("Number of valid pairs: " + result);
    }
}
