import java.util.Scanner;

public class Day4_que1 
{

    public static boolean isPalindrome(String str) 
    {

        int left = 0;
        int right = str.length() - 1;

        while (left < right) 
        {
            if (str.charAt(left) != str.charAt(right)) 
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    // Method to check if the substring is already in the array
    public static boolean isInArray(String[] arr, String str, int count) 
    {
        for (int i = 0; i < count; i++) 
        {
            if (arr[i].equals(str)) 
            {
                return true;
            }
        }
        return false;
    }

    // Method to find the number of distinct palindromic substrings of a given length
    public static void countString(String s, int length) 
    {
        int len = s.length();
        s = s.toLowerCase();
        String[] palindromicSubstrings = new String[len];
        int count = 0;

        for (int i = 0; i <= len - length; i++) 
        {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring) && !isInArray(palindromicSubstrings, substring, count)) {
                palindromicSubstrings[count] = substring;
                count++;
            }
        }

        System.out.println("Number of distinct palindromic substrings of length " + length + " in '" + s + "': " + count);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        String st = "";
        int length;
        
        System.out.println("Enter a string: ");
        st = sc.nextLine();
        
        System.out.println("Enter the length of substrings to check: ");
        length = sc.nextInt();

        countString(st, length);
    }
}
