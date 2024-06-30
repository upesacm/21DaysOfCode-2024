import java.io.*;
import java.util.*;

public class Solution {
    public static int Max(String str){
        int y=0;
        int x=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)=='x')
            x++;
            else
            y++;
        }
        
        int result=0,count=0;
        ArrayList<Integer> pre=new ArrayList<>();
        ArrayList<Integer> suf=new ArrayList<>();
        
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)=='x')
            count++;
            else
            pre.add(count);
        }
        
        pre.add(count);
        count=0;
        
        for(int i=str.length()-1;i>0;i--)
        {
            if(str.charAt(i)=='x')
            count++;
            else
            suf.add(count);
        }
        
        suf.add(count);
        
        
        int l=0;
        int h=y;
        while(l<=h)
        {
            int mid=(l+h)/2;
            boolean check=false;
            for(int i=0;i<=mid;i++)
            {
                int left=x;
                left-=pre.get(i);
                left-=suf.get(mid-i);
                
                if(left<=mid)
                {
                    check=true;
                    break;
                }
            }
            if(check)
            {
                result=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        //System.out.println(" y="+y+" x="+x);
        return result;
    }

    public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    String str = scan.nextLine();
        System.out.println(Max(str));
    }
}
