import java.math.BigInteger;
import java.util.Scanner;

public class DigitSum {

    public static int sumDigits(BigInteger number) {
        if (number.compareTo(BigInteger.TEN) < 0) {
            return number.intValue();
        } else {
            BigInteger sum = BigInteger.ZERO;
            while (number.compareTo(BigInteger.ZERO) > 0) {
                sum = sum.add(number.mod(BigInteger.TEN));
                number = number.divide(BigInteger.TEN);
            }
            return sumDigits(sum);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a large integer: ");
        BigInteger number = scanner.nextBigInteger();

        int result = sumDigits(number);
        System.out.println("The single digit result is: " + result);

        scanner.close();
    }
}
