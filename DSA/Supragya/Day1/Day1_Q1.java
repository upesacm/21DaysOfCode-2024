/**
 * Question 1:
 * Rohan and Raju have a candy where each square has a number. Rohan wants to find out how many ways he 
 * can break the bar into a contiguous segment such that:
 * The segment length matches Raju's birth month.
 * The sum of the numbers in the segment equals Raju's birth day.
 * 
 * Inputs:
 * An array of integers representing the chocolate squares.
 * Two integers representing Raju's birth day and birth month.
 * 
 * Output:
 * The number of valid ways to divide the bar.
 * 
 * Example:
 * Candy = [2, 2, 1, 3, 2]
 * day = 4
 * month = 2
 * 
 * Output: 2
 */
import java.util.*;
public class Day1_Q1{
    public static int Ways(List<Integer> arr, int sum, int seq){
        int count =0;
        for(int i=0;i<arr.size();i++){
            int temp=0;
            if(i+seq>arr.size()){
                break;
            }
            for(int j=i;j<i+seq;j++){
                temp+=arr.get(j);
            }
            if(temp==sum){
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] candy = new int[n];
        for(int i=0; i<n; i++){
            candy[i] = scan.nextInt();
        }
        int day = scan.nextInt();
        int month = scan.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i:candy){
            arr.add(i);
        }
        System.out.println("Number of ways to divide the bar" + Ways(arr, day, month));
    }
}