public class Day_13_Q2 {
    public static int reverseNumber(int number) {
        if (number < 10){return number;}
        int remainder = number % 10;
        int reversedNumber = reverseNumber(number / 10);
        int numberOfDigits = (int) Math.log10(number) + 1;
        return remainder*(int) Math.pow(10, numberOfDigits - 1)+ reversedNumber;
    }

    public static void isPalindrome(int num) {
        int temp = reverseNumber(num);
        if (num == temp) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static void main(String[] args) {
        //test case-1
        isPalindrome(121);
        //test case-2
        isPalindrome(231);
    }

}