public class Fibonacci {
    public static int fibonacci(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("Input should be a positive integer.");
        } else if (n == 1) {
            return 0;
        } else if (n == 2) {
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    public static void main(String[] args) {
        int n = 5;
        System.out.println("Output: " + fibonacci(n));
    }
}
