import java.util.Scanner;

public class Q1{
    public static void studentsClassToBeConducted(int arrival_times[],int threshold){
        int count=0;
        for(int i=0;i<arrival_times.length;i++){
            if(arrival_times[i]<0){
                count++;
            }
        }
        if(count>=threshold){
            System.out.println("NO");
        }else{
            System.out.println("YES");
        }
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter number of students:");
        int n=in.nextInt();
        int arrival_times[]=new int[n];
        System.out.println("Enter students arrival times:");
        for(int i=0;i<n;i++){
            arrival_times[i]=in.nextInt();
        }
        System.out.println("Enter threshold number for class to be conducted");
        int threshold=in.nextInt();
        studentsClassToBeConducted(arrival_times,threshold);
        in.close();
    }
}