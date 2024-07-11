/**
 * Question 1: 
 * A professor has a class of students and wants to know if the class should be cancelled based on student arrival times.
 * The class is cancelled if fewer than a threshold number of students arrive on time.
 * 
 * Inputs:
 * An integer representing the threshold number of students.
 * An array of integers representing arrival times, where a non-positive integer indicates on-time arrival. 
 * 
 * Output:
 * YES" if the class is cancelled, "NO" otherwise.
 * 
 * Example:
 * threshold = 3
 * arrival_times = [-1, -3, 4, 2]
 * 
 * Output: YES
 */
import java.util.*;
public class Day2_Q1 {
    public static boolean classCancelled(int threshold, ArrayList<Integer> arrival_times) {
        for(int i : arrival_times){
            if(i<=0){
                threshold--;
            }
        }
        return threshold<=0?false:true;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int threshold = scan.nextInt();
        int n = scan.nextInt();
        ArrayList<Integer> arrival_times = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arrival_times.add(scan.nextInt());
        }
        System.out.println("Class Cancelled: " + classCancelled(threshold, arrival_times));
    }
}
