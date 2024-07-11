public class DigitSum {
    public static int sumDigits(int number) {
        if (number < 10) {
            return number;
        }
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sumDigits(sum);
    }

    public static void main(String[] args) {
        int number = 9875;
        System.out.println("The sum of digits until a single digit for " + number + " is: " + sumDigits(number));
    }
}
