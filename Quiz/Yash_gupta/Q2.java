import java.io.*;
import java.util.*;

public class Q2 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc= new Scanner(System.in);
        String str=sc.next();
        System.out.println(mindig(str));
    }
    public static int mindig(String str)
    {
        int n=str.length();
        int countX[]=new int[n+1];
        for(int i=0;i<n;i++){
            countX[i+1]=countX[i]+(str.charAt(i)=='x' ? 1:0);
        }
        int countY[]=new int[n+1];
        for(int i=n-1;i>=0;i--){
            countY[i]=countY[i+1]+(str.charAt(i)=='y' ? 1:0);
        }
        int min=Integer.MAX_VALUE;
        for(int i=0;i<=n;i++)
        {
            int dig0=countX[i];
            int dig1=countY[i];
            int maxdig=Math.max(dig0,dig1);
            if(maxdig<min)
            {
                min=maxdig;
            }
        }
        return min;
    }
}