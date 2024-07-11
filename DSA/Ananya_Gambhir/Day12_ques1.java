import java.util.Scanner;
public class Day12_ques2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();
        int result = recursiveDigitSum(number);
        System.out.println("Output: " + result);
        scanner.close();
    }
    public static int recursiveDigitSum(int number) {
        if (number < 10) {
            return number;
        }
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        
        return recursiveDigitSum(sum);
    }
}
