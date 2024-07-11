public class Day_12_Question_1 {
    public static int nFibonacci(int n) {
        if (n == 1 || n == 0)
            return n;
        
        return nFibonacci(n-1) + nFibonacci(n-2);
    }
    public static void main(String[] args) {
        System.out.println(nFibonacci(5));
    }
}
