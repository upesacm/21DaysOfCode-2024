import java.util.*;
public class Day1_ques1 {
    public static int countDivisiblePairs(int[] arr,int k){
        int count = 0;
        int n = arr.length;
        int[] freq = new int[k];
        
        for (int i = 0; i < n; i++) {
            int remainder = arr[i] % k;
            
            int complement = (k - remainder) % k;
            
            count += freq[complement];
            
            freq[remainder]++;
        }        
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter the number of elements in the array:");
        int n = sc.nextInt();
        
        int[] arr = new int[n];
        
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        System.out.println("Enter the value of k:");
        int k = sc.nextInt();
        
        System.out.println("Number of valid pairs: " + countDivisiblePairs(arr, k));
    }
}
