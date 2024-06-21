// package 21DaysOfCode-2024.DSA.Sujal500108589.Day1;
public class sumDivisibleByK {
    public static int sumOfPairs(int []arr,int k){
        int count=0;
        for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
               if((arr[i]+arr[j])%k==0){
                  count++;
               }
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int arr[]={1,3,2,6,1,2};
        int k=3;
        System.out.println("Total pairs:"+ sumOfPairs(arr,k));
    }
}
