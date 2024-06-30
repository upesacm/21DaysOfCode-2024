//Question-2
// Author: Ayush Dey
import java.util.Scanner;

public class Q2{

    public static int countPairs(int[] arr, int k) {
        int n = arr.length;
        int[] freq = new int[k];

        // Count occurrences of remainders
        for (int i = 0; i < n; i++) {
            freq[(arr[i] % k + k) % k]++;
        }

        // Calculate the number of valid pairs
        int sum = freq[0] * (freq[0] - 1) / 2;
        for (int i = 1; i <= k / 2 && i != (k - i); i++) {
            sum += freq[i] * freq[k - i];
        }
        if (k % 2 == 0) {
            sum += (freq[k / 2] * (freq[k / 2] - 1) / 2);
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();

        int result = countPairs(arr, k);
        System.out.println(result);

        scanner.close();
    }
}
