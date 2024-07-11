import java.util.HashSet;
import java.util.Set;
public class Solution1_Day4 {
    public static boolean isPalindrom(String s){
        int left = 0, right = s.length() -1;
        while(left < right){
            if(s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }return true;

    }
    public static int countSubStrings(String str, int length){
        Set<String> palindrome = new HashSet<>();
        for(int i =0; i<= str.length()-length; i++){
            String subString = str.substring(i, i+length);
            if(isPalindrom(subString)){
                palindrome.add(subString);
            }

        }
        return palindrome.size();
    }
    public static void main(String[] args){
        String string = "ababa";
        int length= 3;
        System.out.println("number of distinct palindrom subString are:" + countSubStrings(string, length));
    }


}
