/*
 
**Question 1:** 
Rohan and Raju have a candy where each square has a number. Rohan wants to find out how many ways she can break the bar into a contiguous segment such that:
1. The segment length matches Raju's birth month.
2. The sum of the numbers in the segment equals Raju's birth day.
##### Inputs:
- An array of integers representing the chocolate squares.
- Two integers representing Raju's birth day and birth month.
##### Output:
- The number of valid ways to divide the bar.
##### Example:
Candy = [2, 2, 1, 3, 2]
day = 4
month = 2
*/
public class dayOne_Ques1{
   
    public static void main (String[] args) {
        int[] arr = {2, 2, 1, 3, 2};
        int day = 4;
        int month = 2;
        System.out.println(birthdayBruteforce(arr, day, month));
        // System.out.println(birthdayOptimal(arr, day, month));
    }
    private static int birthdayBruteforce(int arr[],int day, int month){
        int res=0;//for the resultant variable
        for(int i=0;i<arr.length-month;i++){
            int sum=0;
            for(int j=i;j<i+month;j++){
                sum+=arr[j];
            }
            if(sum==day){
                res++;
            }
        }

        return res;
    }
    private static int birthdayOptimal(int[] arr, int day, int month) {
        int res = 0;
        int sum = 0;

        for (int i = 0; i < month; i++) {
            sum += arr[i];
        }

        if (sum == day) {
            res++;
        }

        for (int i = month; i < arr.length; i++) {
            sum += arr[i] - arr[i - month];
            //arr[i-month] is the element which is going out of the window and window size is of month length
            if (sum == day) {
                res++;
            }
        }

        return res;
    }
    



}