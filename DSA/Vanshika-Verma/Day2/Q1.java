import java.util.Scanner;
public class day2q1{
    
    public static String check(int thresh, int[]arr )
    {
        int count =0;
        for(int i : arr){
            if (i <= 0)
            count++;
        }
         if(count<thresh){
         return "Yes";
        }
         else
       {  return "No";}
         
    }
    
    public static void main (String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter thhe no of threshold students");
    int thresh = sc.nextInt();
    System.out.print("Enter the number of students: ");
    int n = sc.nextInt();
    int arrtime[] = new int[n];
    System.out.print("Enter the arrival time of students: ");
    for (int i = 0; i < n; i++) {
        arrtime[i] = sc.nextInt();
    }  
    System.out.println(check(thresh,arrtime));
}
}
