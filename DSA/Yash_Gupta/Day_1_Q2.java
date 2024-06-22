public class Day_1_Q2{
    public static int sumpairdivisiblebyk(int arr[],int k)
    {
        int count=0;
        /*Using brute force method */
        for(int i=0;i<arr.length-1;i++)
        {
            for(int j=i+1;j<arr.length;j++)
            {
                if((arr[i]+arr[j])%k==0){count++;}
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int pairs_case1[]={1, 3, 2, 6, 1, 2}; //Test case 1
        System.out.println(sumpairdivisiblebyk(pairs_case1, 3));

        int pairs_case2[]={1, 3,5,6,7, 2, 6, 1, 2}; //Test case 2
        System.out.println(sumpairdivisiblebyk(pairs_case2, 3));
    }
}