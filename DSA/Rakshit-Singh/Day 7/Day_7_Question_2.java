import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Day_7_Question_2 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        int min=s.length();
        int left_x=0;
        for(int x=0;x<s.length();x++){
            char ch=s.charAt(x);
            if(ch=='x'){
                left_x++;
            }
        }
        for(int x=0;x<=s.length()-2;x++){
            int start=x;
            int end=s.length()-1;
            int digx=0,digy=0;

            for(int y=0;y<=start;y++){
                char ch=s.charAt(y);
                if(ch=='x'){
                    digx++;
                }
                else{
                    digy++;
                }
            }
            int leftover_x=left_x-digx;
            int value=Math.max(leftover_x,digy);
            if(value<min){
                min=value;
            }
            while(start<end){
                char ch=s.charAt(end);
                if(ch=='x'){
                    digx++;
                }
                else{
                    digy++;
                }
                leftover_x=left_x-digx;
                value=Math.max(leftover_x,digy);
                if(value<min){
                    min=value;
                }
                end--;
            }

        }
        System.out.println(min);
    }
}