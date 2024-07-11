import java.util.*;
public class Day2_1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int size = scn.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter the elements of the leaderboard array:");
        int count = 0;
        for(int i = 0; i < size; i++) {
            arr[i] = scn.nextInt();
        }
        System.out.println("Enter the target:");
        int target = scn.nextInt();
        for(int i =0;i<size;i++){
            if(arr[i]<0){
                count++;
            }
        }
            if(count<target){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
    }
}