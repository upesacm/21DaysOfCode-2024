//Yash gupta 500125397
public class Day_8_Q1 {

    public static int sumArray(int arr[])
    {
        int sum=0;
        for(int i=0;i<arr.length;i++)
        {
            sum=sum+arr[i];
        }
        return sum;
    }
    public static int getMaxEqualHeight(int[] h1, int[] h2, int[] h3) {
        int sum1 = sumArray(h1);
        int sum2 = sumArray(h2);
        int sum3 = sumArray(h3);
        
        int i = 0, j = 0, k = 0;
        
        while (true) {
            if (i == h1.length || j == h2.length || k == h3.length) {
                return 0;
            }

            if (sum1 == sum2 && sum2 == sum3) {
                return sum1;
            }
            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= h1[i++];
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= h2[j++];
            } else {
                sum3 -= h3[k++];
            }
        }
    }

    public static void main(String[] args) {
        //test case-1
        int[] stack1 = {3, 2, 1, 1, 1};
        int[] stack2 = {4, 3, 2};
        int[] stack3 = {1, 1, 4, 1};
        System.out.println(getMaxEqualHeight(stack1, stack2, stack3)); 
    }
}
