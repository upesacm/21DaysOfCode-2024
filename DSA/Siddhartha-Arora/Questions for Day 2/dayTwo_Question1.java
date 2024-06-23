
/*
 *  * # Questions for Day 2 - (22/06/2024)

## DSA


#### Question 1: A professor has a class of students and wants to know if the class should be cancelled based on student arrival times. The class is cancelled if fewer than a threshold number of students arrive on time.
##### Inputs:
- An integer representing the threshold number of students.
- An array of integers representing arrival times, where a non-positive integer indicates on-time arrival.
Output:
- YES" if the class is cancelled, "NO" otherwise.
##### Example:

threshold = 3

arrival_times = [-1, -3, 4, 2]

Output: YES
 */
public class dayTwo_Question1 {
    public static void main(String args[]){
        int threshold=3;
        int arr[]={-1,-3,4,2};
        BruteForce(threshold,arr);
    }
    private static void BruteForce(int threshold, int[] arr) {
        int compare=0;
        for(int nums:arr){
            if(nums<=0)compare++;
        }
        boolean flag=true;
        if(compare<threshold)flag=false;
        System.out.println(flag?"NO":"YES");



    }
    
}