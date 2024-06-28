import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Day_7_Question_1 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int ar[]=new int[n];
        String track=",";
        for(int x=0;x<n;x++){
            ar[x]=sc.nextInt();
            track+=ar[x]+",";
        }
        
        int properties=sc.nextInt();
        
        int bought=0,cost=0,difference=1;
        
        Arrays.sort(ar);
        
        
        while(bought<properties){
            for(int x=0;x<ar.length;x++){
                int left=ar[x]-difference;
                String check=","+left+",";
                if(track.indexOf(check)==-1){
                    cost+=difference;
                    track+=left+",";
                    bought++;
                }
                if(bought>=properties){
                    break;
                }
                int right=ar[x]+difference;
                String check2=","+right+",";
                if(track.indexOf(check2)==-1){
                    cost+=difference;
                    track+=right+",";
                    bought++;
                }
                if(bought>=properties){
                    break;
                    
                }
            }
            difference++;
        }
        
        System.out.println(cost);
    }
}