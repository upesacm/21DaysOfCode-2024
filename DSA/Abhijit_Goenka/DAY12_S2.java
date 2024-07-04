/*
 Given a number, recursively sum its digits until a single digit is obtained.

Inputs:
A large integer.
Output:
The single digit result.
Example:
number = 9875

Output: 2
 */
import java.util.*;
class DAY12_S2
{
    public static int sumDigits(int number) 
    {
        if (number < 10) 
        {
            return number;
        } else 
        {
            int sum = 0;
            while (number != 0) 
            {
                sum += number % 10;
                number /= 10;
            }
            return sumDigits(sum);
        }
    }
    public static void main(String[] args) 
    {
        int number = 9875;
        System.out.println(sumDigits(number));
    }
}
