// Yash Gupta 500125397
public class Day_4_Q1 {
    //function to check if a string is palindrome or not
    public static boolean isPalindrome(String s)
    {
        if(s==null) return false;
        //checking if a string is palindrome
        for(int i=0;i<s.length()/2;i++)
        {
            if(s.charAt(i)!=s.charAt(s.length()-i-1))
                return false;
        }
        return true;
    }
    public static int countPalindromicSubstring(String line,int substring_length)
    {
        if(line==null){return 0;}

        int count=0;
        //making substring of specified length and checking if substring is palindrome
        for(int i=0;i<line.length()-substring_length+1;i++)
        {
            if(isPalindrome(line.substring(i, i+substring_length)))
            {
                count++;
            }
        }
        return count;
    }
    public static void main(String[] args) {
        String test_case[]={"ababa","aaca","abcas"};//test cases
        for(int i=0;i<test_case.length;i++){
            System.out.println(countPalindromicSubstring(test_case[i], 1));
        }
    }
}
//time complexity O(n*k)
//auxillary space O(1)