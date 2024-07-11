import java.util.Scanner;

public class Day12_Solution2 {

    public static int singleDigitSum(int number){
        if(number < 10){
            return number;
        }
        else{
            int sum = 0;
            while(number > 0){
                sum += number % 10;
                number /= 10;
            }
            return singleDigitSum(sum);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        scanner.close();

        System.out.println(singleDigitSum(number));
    }
}