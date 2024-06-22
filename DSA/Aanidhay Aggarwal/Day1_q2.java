import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CountPairs {
    public static int countPairs(int[] arr, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        int pairs = 0;

        for (int num : arr) {
            int remainder = num % k;
            pairs += count.getOrDefault((k - remainder) % k, 0);
            count.put(remainder, count.getOrDefault(remainder, 0) + 1);
        }

        return pairs;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        System.out.print("Enter the array elements (space-separated): ");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();

        int result = countPairs(arr, k);
        System.out.println("Number of valid pairs: " + result);
    }
}
