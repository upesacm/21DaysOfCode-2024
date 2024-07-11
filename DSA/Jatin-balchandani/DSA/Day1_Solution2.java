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

class Solution2
{
    public static int countPairs(int[] arr, int k)
    {

        int[] remainderCounts = new int[k];
        int pairCount = 0;
        for (int number : arr) {

            int remainder = number % k;
            int complement = (k - remainder) % k;
            pairCount += remainderCounts[complement];


            remainderCounts[remainder]++;
        }


        return pairCount;
    }

    public static void main(String[] args)
    {

        int[] arr = {1, 3, 2, 6, 1, 2};
        int k = 2;

        System.out.println(countPairs(arr, k));
    }

}
