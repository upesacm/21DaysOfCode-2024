import java.util.Scanner;

public class ChocolateBar {

    public static int findWays(int[] arr, int days, int months) {
        int sum = 0;
        int output = 0;

        for (int i = 0; i <= arr.length; i++) {
            if (i < arr.length) {
                sum += arr[i];
            }
            if (i >= months) {
                sum -= arr[i - months];
            }
            if (i >= months - 1) {
                if (sum == days) output++;
            }
        }

        return output;
    }

    public static void main(String[] args) {
        // array
        int[] arr = {2, 2, 1, 3, 2, 2};
        int arr_size = arr.length;
        System.out.print("The array is: ");
        for (int i = 0; i < arr_size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        // day input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the day: ");
        int day = scanner.nextInt();

        // month input
        System.out.print("Enter the month: ");
        int month = scanner.nextInt();

        // program calculation
        System.out.println(findWays(arr, day, month));
    }
}
