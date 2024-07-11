public class SumDigits {
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
        int number = 9875;
        System.out.println("Output: " + sumDigits(number));
    }
}
