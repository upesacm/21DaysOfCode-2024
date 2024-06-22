import java.util.*;
class candy
{
    public static void main(String args[])
    {
    Scanner sc=new Scanner(System.in);
    int day,month,n,count=0,sum=0,flag=0;
    System.out.println("Enter number of squares in candy:");
    n=sc.nextInt();
    int arr[]=new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=sc.nextInt();
    }
    System.out.print("Day=");
    day=sc.nextInt();
    System.out.print("Month=");
    month=sc.nextInt();
    for(int j=0;j<n;j++)
    {
        int a=j;
        sum=0;
        for(int k=0;k<month;k++)
        {
            
            if(a==arr.length)//to check if the iteration does not go out of array bounds
            {
                flag=1;
                break;
            }
            sum=sum+arr[a];
            if(sum==day)
            {
                count=count+1;
            }
            a++;
        }
        if(flag==1)
        {
            break;
        }
    }
    System.out.println("No of ways in which bar can be divided="+count);

    }
}
