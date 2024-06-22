public class que1 {
    public static void main(String[] args) {
        int[]arr={2, 4, 1, 3, 2 ,3,1};
        int day=6;
        int month=2;
        System.out.println(numberOfsegments(arr,day,month));

    }
    static int numberOfsegments(int[]arr,int day,int month)
    {
        int sum;
        int count=0;
        for(int i=0;i<arr.length-1;i++)
        {   sum=0;
            for(int j=1+i;j<month+i;j++)
            {
               sum+=arr[i]+arr[j];
               if(sum==day)
               {
                count++;
               }
            }
        }
        return count;
    }
}
