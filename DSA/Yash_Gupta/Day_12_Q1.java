public class Day_12_Q1 {
    public static int fibonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        //test case-1
        System.out.println(fibonacci(12));
        //test case-2
        System.out.println(fibonacci(1));
        //test case-3
        System.out.println(fibonacci(3));
    }    
}