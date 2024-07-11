import java.util.Scanner;

public class SumDigits {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        long number = scanner.nextLong();
        int result = sumDigits(number);
        System.out.println("The sum of the digits of " + number + " is: " + result);
    }

    public static int sumDigits(long number) {
        if (number < 10) {
            return (int) number;
        } else {
            int sum = 0;
            while (number > 0) {
                sum += number % 10;
                number /= 10;
            }
            return sumDigits(sum);
        }
    }
}
