package DSA.Nizaul_Rahman;

public class Day1Q2 {

    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 6, 1, 2};
        int k = 3;

        int result = countDivisiblePairs(arr, k);
        System.out.println("Number of valid pairs: " + result);
    }

    public static int countDivisiblePairs(int[] arr, int k) {
        int count = 0;
        int n = arr.length;
        int[] remainderCounts = new int[k];

        for (int j = 0; j < n; j++) {
            int rem_j = arr[j] % k;
            int target_rem = (k - rem_j) % k;

            count += remainderCounts[target_rem];
            remainderCounts[rem_j]++;
        }

        return count;
    }
}
