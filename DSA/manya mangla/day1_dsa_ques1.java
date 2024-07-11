public class ChocolateBar {

    public static void main(String[] args) {
        int[] candy = {2, 2, 1, 3, 2};
        int day = 4;
        int month = 2;

        int result = countSegments(candy, day, month);
        System.out.println(result);  // Output: 2
    }

    public static int countSegments(int[] candy, int day, int month) {
        int count = 0;

        // Iterate through the array up to the point where a segment of 'month' length can start
        for (int i = 0; i <= candy.length - month; i++) {
            int sum = 0;
            
            // Calculate the sum of the segment of length 'month'
            for (int j = i; j < i + month; j++) {
                sum += candy[j];
            }
            
            // If the sum matches Raju's birth day, increment the count
            if (sum == day) {
                count++;
            }
        }

        return count;
    }
}
