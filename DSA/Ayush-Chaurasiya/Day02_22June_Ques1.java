import java.util.Scanner;

public class Day02_22June_Ques1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count=0;

        System.out.print("Enter lenght of class: ");
        int length = scanner.nextInt();
        
        System.out.print("Enter threshold value: ");
        int threshold = scanner.nextInt();

        System.out.print("Enter arrival time of students: ");
        int[] arrival_times = new int[length]; 
        for(int i=0; i<length; i++){
            arrival_times[i] = scanner.nextInt();
            if(arrival_times[i] <= 0){
                count++;
            }
        }

        if(count < threshold){
        System.out.println("Yes");
        }    
        else{
            System.out.println("No");
        }
        
        scanner.close();
    }
}
