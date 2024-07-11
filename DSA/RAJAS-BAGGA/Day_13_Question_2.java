public class Day_13_Question_2 {
    
    static int reverse(int n, int temp) {
        if (n == 0)
            return temp;
        
        temp = (temp * 10) + (n % 10);
        return reverse(n / 10, temp);
    }
    
    public static String isPalindrome(int n) {
        if (n == reverse(n, 0))
            return "YES";
        return "NO";
    }
    public static void main(String[] args) {
        System.out.println(isPalindrome(12));
    }
}
