import java.util.*;
public class Day1_1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int size = scn.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter the elements of the array:");
        for(int i = 0;i<size;i++){
            arr[i] = scn.nextInt();
        }
        System.out.println("Enter the month:");
        int month = scn.nextInt();
        System.out.println("Enter the day:");
        int day = scn.nextInt();
        int count = 0;
        for(int i =0;i<size-month; i++){
            int sum = 0;
            for(int j =i; j<i+month;j++){
                sum = sum+arr[j];
            }
            if(sum == day){
                count++;
            }
        }
        System.out.println("The total number of possibilities are:"+ count);
    }
    
}
