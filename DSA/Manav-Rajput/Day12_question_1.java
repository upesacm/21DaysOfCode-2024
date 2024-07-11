public class Fibonacci {

    // Function to compute the n-th Fibonacci number
    public static int fibonacci(int n) {
        // Base cases
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            // Recursive call
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    // Main method to test the function
    public static void main(String[] args) {
        int n = 5;  // You can change this value to test other inputs
        int result = fibonacci(n);
        System.out.println("Fibonacci number at position " + n + " is: " + result);
    }
}
