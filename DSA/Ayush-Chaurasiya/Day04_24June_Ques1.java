import java.util.HashSet;
import java.util.Scanner;

public class Day04_24June_Ques1 {
    
    public static boolean isPalindrome(String substring){
        int len = substring.length();
        for(int i=0; i<len; i++){
            if(substring.charAt(i) != substring.charAt(len-1 - i)){
                return false;
            }
        }
        return true;
    }

    public static int findNumberOfPalindrome(String input, int length){
        HashSet<String> mySet = new HashSet<>();
        for(int i = 0; i <= input.length() - length; i++){
            String substr = input.substring(i, i + length);
            if(isPalindrome(substr)){
                mySet.add(substr);
            }
        }
        return mySet.size();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter string: ");
        String input = scanner.nextLine();

        System.out.print("Enter length of palindrome: ");
        int length = scanner.nextInt();

        System.out.println(findNumberOfPalindrome(input, length));
        scanner.close();
    }
}
