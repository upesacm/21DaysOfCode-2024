/*
  Write a function to compute the n-th Fibonacci number using recursion.

Inputs:
An integer n.
Output:
The n-th Fibonacci number.
Example:
n = 5
 */
import java.util.*;
class DAY12_S1 
{
    public static int fibonacci(int n) 
    {
        if (n == 0) 
        {
            return 0;
        } else if (n == 1) 
        {
            return 1;
        } else 
        {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    public static void main(String[] args) 
    {
        int n = 5;
        System.out.println(fibonacci(n));
    }
}
