public class Day_12_Q2 {
    public static void main(String[] args) {
        //test case-1
        System.out.println(sumDigits(9875));
        //test case-2
        System.out.println(sumDigits(123421));
        //test case-2
        System.out.println(sumDigits(111111));


    }
    public static int sumDigits(int num)
    {
        if (num < 10) {
            return num;
        }
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sumDigits(sum);
    }
}
