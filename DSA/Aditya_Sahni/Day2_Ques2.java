public class que2 {
public static void main(String[] args) {
    int[]arr={1, 3, 2, 6, 1, 2};
    int target=3;
    System.out.println(findSum(arr,target));
}
static int findSum(int[]arr,int target)
{
    int count=0;
    for(int i=0;i<arr.length;i++)
    {
        for(int j=1+i;j<arr.length;j++)
        {
            if((arr[i]+arr[j])%target==0)
            {
                count++;
            }
        }
    }
    return count;
}
    
}
