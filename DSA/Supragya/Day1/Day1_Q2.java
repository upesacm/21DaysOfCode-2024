/**
 * Question 2:
 * Given an array of integers and an integer k, determine the number of (i, j) pairs where i < j 
 * and the sum of the pair is divisible by k.
 * 
 * Inputs:
 * An array of integers.
 * An integer k.
 * 
 * Output:
 * The number of valid (i, j) pairs.
 * 
 * Example:
 * arr = [1, 3, 2, 6, 1, 2]
 * k = 3
 * 
 * Output: 5
 */
import java.util.*;
public class Day1_Q2 {
    public static int Pairs(ArrayList<Integer> arr,int k){
        int pairs=0;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                if( i<j && (arr.get(i)+arr.get(j))%k==0 ){
                    pairs++;
                }
            }
        }
        return pairs;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n= scan.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0;i<n;i++){
            arr.add(scan.nextInt());
        }
        int k = scan.nextInt();
        System.out.println("Number of Pairs = "+Pairs(arr,k));
    }
}
