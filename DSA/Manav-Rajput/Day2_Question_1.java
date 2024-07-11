import java.util.*;
class day2
{
    void decision(int arr[],int len,int th)
    {
        int count=0;
        for(int i=0;i<len;i++)
        {
            if(arr[i]<0)
            {
                count=count+1;
            }
        }
        if(count<th)
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n,th;
        System.out.print(" number of students coming for class=");
        n=sc.nextInt();
        System.out.println("Threshold=");
        th=sc.nextInt();
        int arr[]=new int[n];
        System.out.println("Time of arrival for "+n+" students=");
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        day2 obj=new day2();
        obj.decision(arr, n, th);
    }
}
