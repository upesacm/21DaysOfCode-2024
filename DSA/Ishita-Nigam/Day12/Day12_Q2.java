import java.util.Scanner;

public class Day12_Q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a large integer: ");
        long number = scanner.nextLong();
        scanner.close();

        int result = sumDigitsUntilSingleDigit(number);
        System.out.println("The single digit result is: " + result);
    }

    public static int sumDigitsUntilSingleDigit(long number) {
        if (number < 10) {
            return (int) number;
        }

        long sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }

        return sumDigitsUntilSingleDigit(sum);
    }
}
