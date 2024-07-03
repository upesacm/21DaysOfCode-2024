import java.util.*;

public class Day12_que2 {

    public static int sumDigitsUntilSingle(int number) {
        if (number < 10) {
            return number;
        }

        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }

        return sumDigitsUntilSingle(sum);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a large integer:");
        int number = sc.nextInt();
        int result = sumDigitsUntilSingle(number);
        System.out.println("The single digit result is: " + result);
        sc.close();
    }
}
