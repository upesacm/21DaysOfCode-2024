public class Day12_Q1 {
    public static void main(String[] args) {
        int n = 5;
        System.out.println("Fibonacci number at position " + n + " is: " + fibonacci(n));
    }

    public static int fibonacci(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("n must be a positive integer");
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
