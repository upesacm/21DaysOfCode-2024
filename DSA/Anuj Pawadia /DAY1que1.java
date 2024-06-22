public class ChocolateSegment {
    public static int countValidSegments(int[] candy, int day, int month) {
        int count = 0;
        int n = candy.length;

        // Calculate the sum of the first 'month' elements
        int currentSum = 0;
        for (int i = 0; i < month; i++) {
            currentSum += candy[i];
        }

        // Check the first window
        if (currentSum == day) {
            count++;
        }

        // Slide the window across the array
        for (int i = month; i < n; i++) {
            currentSum += candy[i] - candy[i - month];
            if (currentSum == day) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        int[] candy = {2, 2, 1, 3, 2};
        int day = 4;
        int month = 2;

        int result = countValidSegments(candy, day, month);
        System.out.println(result);  // Output: 2
    }
}
