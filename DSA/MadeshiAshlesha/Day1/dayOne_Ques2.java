import java.util.*;
public class dayOne_Ques2 {
    public static void main (String args[]){
        int[] arr = {1, 3, 2, 6, 1, 2};
        int k = 3;
        System.out.println(getRes(arr, k));
        
    }
    private static int getRes(int[] arr, int k) {
        int res=0;
        for(int i=0;i<arr.length-1;i++){
            for(int j=i+1;j<arr.length;j++){
                if((arr[i]+arr[j])%k==0){
                    res++;
                }
            }
        }
        return res;
    }
    
        
}
