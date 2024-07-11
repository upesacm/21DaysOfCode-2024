import java.util.*

public class isClassCancelled{
    public static String isClassCancelled(int threshold_no, int[] arrival_times) {
       int k = 0;
       for (int i = 0; i < arrival_times.length; i++) {
           if (arrival_times[i] <= 0) {
               k++;
           }
       }
       if (k < threshold_no) {
           return "YES";
       } else {
           return "NO";
       }
   }
   
   public static void main(String[] args) {
       int threshold1 = 3;
       int[] arrivalTimes1 = {-1, -3, 4, 2};
       System.out.println(isClassCancelled(threshold1, arrivalTimes1)); // Output: YES
   }
