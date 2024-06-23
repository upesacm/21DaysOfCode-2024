/**##### Output: 2

**Question 2:** 
Given an array of integers and an integer k, determine the number of (i, j) pairs where i \< j and the sum of the pair is divisible by k.
###### Inputs:
- An array of integers.
- An integer k.
###### Output:
- The number of valid (i, j) pairs.
###### Example:
arr = [1, 3, 2, 6, 1, 2]
k = 3
##### Output: 5
*/
public class dayOne_Ques2 {
    public static void main (String args[]){
        int[] arr = {1, 3, 2, 6, 1, 2};
        int k = 3;
        System.out.println(getRes_BruteForce(arr, k));
        // System.out.println(getRes_Optimal(arr, k));
    }
    private static int getRes_BruteForce(int[] arr, int k) {
        int res=0;// to store the resultant value
        for(int i=0;i<arr.length-1;i++){
            for(int j=i+1;j<arr.length;j++){
                if((arr[i]+arr[j])%k==0){
                    res++;
                }
            }
        }
        return res;
    }
    
        
}
