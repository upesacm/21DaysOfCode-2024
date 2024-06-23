import java.util.Scanner;

public class Day01_21June_Ques2{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = scanner.nextInt();

        System.out.print("Enter divisor: ");
        int k = scanner.nextInt();

        System.out.print(("Enter array : "));
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = scanner.nextInt();
        }
        scanner.close();

        int totalPairs=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((arr[i] + arr[j]) % k == 0) totalPairs++;
            }
        }
        System.out.println("Total Pairs possible: " + totalPairs);
    }
}
