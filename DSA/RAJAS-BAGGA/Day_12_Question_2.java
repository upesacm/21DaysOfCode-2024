public class Day_12_Question_2 {
    public static int digitSum(int n) {
        if (n == 0)
            return 0;
        
        int sum = n % 10 + digitSum(n/10);
        if (sum < 10)
            return sum;
        return digitSum(sum);
    }
    public static void main(String[] args) {
        System.out.println(digitSum(1234));
    }
}
