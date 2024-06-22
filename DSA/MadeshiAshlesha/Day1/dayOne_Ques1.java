import java.util.*;
public class dayOne_Ques1{

    public static void main (String[] args) {
        int[] arr = {2, 2, 1, 3, 2};
        int day = 4;
        int month = 2;
        System.out.println(birthday(arr, day, month));
    }
    private static int birthday(int arr[],int day, int month){
        int res=0;
        for(int i=0;i<arr.length-month;i++){
            int sum=0;
            for(int j=i;j<i+month;j++){
                sum+=arr[j];
            }
            if(sum==day){
                res++;
            }
        }

        return res;
    }
    
    



}
