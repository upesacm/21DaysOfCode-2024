public class DigitSum {
    public static int sumDigits(int number) {
        if (number < 10) {
            return number;
        } else {
            return sumDigits(sumOfDigits(number));
        }
    }
    public static int sumOfDigits(int number) {
        int sum = 0;
        while (number != 0) {
            sum += number % 10;  
            number /= 10;        
        }
        return sum;
    }
    public static void main(String[] args) {
        int number = 9875;  
        int result = sumDigits(number);
        System.out.println("The single digit result of the number " + number + " is: " + result);
    }
}
