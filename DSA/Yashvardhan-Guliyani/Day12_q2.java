public class SumDigitsUntilSingleDigit {
    public static int sumDigits(int n) {
        if (n < 10) {
            return n;
        } else {
            return n % 10 + sumDigits(n / 10);
        }
    }

    public static int sumDigitsUntilSingleDigit(int n) {
        int result = sumDigits(n);
        while (result >= 10) {
            result = sumDigits(result);
        }
        return result;
    }

    public static void main(String[] args) {
        int number = 9875;
        System.out.println("The single digit result for " + number + " is: " + sumDigitsUntilSingleDigit(number));
    }
}
