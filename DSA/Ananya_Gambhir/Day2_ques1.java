import java.util.*;
public class Day2_ques1 {

    public static void isCancel(int n,int time[]){
        int onTime=0;

        for (int i=0;i<time.length; i++) {
            if (time[i] <= 0) {
                onTime++;
            }
        }

        if(onTime<n){
            System.out.println("YES! The class is cancelled.");
        }
        else{
            System.out.println("NO! The class is not cancelled.");
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
            
        System.out.println("Enter the threshold: ");
        int n=sc.nextInt();
        System.out.println("Enter the no of students: ");
        int m=sc.nextInt();
        int time[]=new int[m];
        System.out.println("Enter the arrival times of students: ");
        for (int i = 0; i < m; i++) {
            time[i] = sc.nextInt();
        }

        isCancel(n, time);
        sc.close();
    }
}
