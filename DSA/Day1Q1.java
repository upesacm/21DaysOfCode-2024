/*
Rohan and Raju have a candy where each square has a number. Rohan wants to find out how many ways she can break the bar into a contiguous segment such that:

        The segment length matches Raju's birth month.
        The sum of the numbers in the segment equals Raju's birth day.

        Inputs:
        An array of integers representing the chocolate squares.

        Two integers representing Raju's birth day and birth month.

        Output:
        The number of valid ways to divide the bar.
        Example:
        Candy = [2, 2, 1, 3, 2]

        day = 4

        month = 2

        Output: 2
 */
public class Day1Q1 {
    public static int birthday(int[] s, int d, int m) {
        int count = 0;
            // Iterate over the array
        for (int i = 0; i <= s.length - m; i++) {
            int sum = 0;
            // Sum the subarray of length m
            for (int j = 0; j < m; j++) {
                sum += s[i + j];
            }
            // Check if the sum matches the day
            if (sum == d) {
                count++;
            }
        }

        return count;
    }
    public static void main(String[] args) {
        int[] candy = {2, 2, 1, 3, 2};
        int day = 4;
        int month = 2;
        int result = birthday(candy, day, month);
        System.out.println(result);
    }


}
