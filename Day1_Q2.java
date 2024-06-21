
/*
Given an array of integers and an integer k, determine the number of (i, j) pairs where i < j and the sum of the pair is divisible by k.

Inputs:
An array of integers.

An integer k.

Output:
The number of valid (i, j) pairs.
Example:
arr = [1, 3, 2, 6, 1, 2]

k = 3

Output: 5
 */
public class Day1_Q2 {
    public static int countPairs(int[] arr, int k) {
        int count = 0;
            // Iterate over all pairs (i, j) where i < j
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if ((arr[i] + arr[j]) % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 6, 1, 2};
        int k = 3;
        int result = countPairs(arr, k);
        System.out.println(result);
    }

}
