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
import java.util.*;
class Solution1
{
    public static int countValidSegments(int[] candy, int day, int month) {
        int choco = candy.length;
        int count = 0;


        if (choco < month)
        {
            return count;
        }
        int currentSum = 0;
        for (int i = 0; i < month; i++) {
            currentSum += candy[i];
        }
        if (currentSum == day) {
            count++;
        }
        for (int i = month; i < choco; i++) {

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
        System.out.println(countValidSegments(candy, day, month));
    }
}
