import java.util.Scanner;
public class DigitSum {
    public static int sumDigits(int n) {
        if (n < 10) {
            return n;
        } else {
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            return sumDigits(sum);
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.print("number : ");
        int number = scn.nextInt();
        System.out.println("The single digit result is: " + sumDigits(number));
    }
}
