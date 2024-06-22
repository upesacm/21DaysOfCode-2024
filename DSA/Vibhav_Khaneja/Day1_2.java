import java.util.*;
public class Day1_2{
    public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);  
    System.out.println("Enter the size of the array:"); 
    int size = scn.nextInt();
    int arr[] = new int[size];
    System.out.println("Enter the elements of the array:");
    for(int i = 0; i<size; i++){
        arr[i] = scn.nextInt();
}
    System.out.println("Enter the number we want to compare with");
    int k = scn.nextInt();
    int count = 0;
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(i<j && (arr[i]+arr[j])%k==0){
                count++;  
                System.out.println("Enter the indexes (" + i+ "," + j+ ")"); 
            }
        }
    }
    System.out.println("The total number of possible indexes:"+ count );
  
    }
}