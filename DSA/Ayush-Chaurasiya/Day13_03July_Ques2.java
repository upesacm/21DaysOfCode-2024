import java.util.Scanner;

public class Day13_03July_Ques2 {

    private static boolean checkPalindrome(int number, int len) {
        if (len <= 1) {
            return true;
        }
        int firstDigit = (int)(number / Math.pow(10, len - 1));
        int lastDigit = number % 10;
        if (firstDigit != lastDigit) {
            return false; 
        }
        number = (number % (int) Math.pow(10, len - 1)) / 10;
        return checkPalindrome(number, len - 2);
    }


    public static String isPalindrome(int number) {
        int originalNumber = number;
        int len = 0;
        while (number > 0) {
            len++;
            number /= 10;
        }
        if (checkPalindrome(originalNumber, len)) {
            return "YES";
        } else {
            return "NO";
        }
    }

    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        scanner.close();

        System.out.println(isPalindrome(number));
    }
}
