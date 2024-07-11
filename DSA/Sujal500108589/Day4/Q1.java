import java.util.HashSet;
import java.util.Set;

public class Q1 {
    public static void checkPalindromicSubtring(String s,int len){
        Set<String> palindromes=new HashSet<>();
        for(int i=0;i<=s.length()-len;i++){
            String substring=s.substring(i, i+len);
            if(isPalindrome(substring)){
                palindromes.add(substring);
            }
        }
        System.out.println("Number of distinct substring palindromes:"+palindromes.size());
    }
    public static boolean isPalindrome(String s){
        int left=0;
        int right=s.length()-1;
        while(left<right){
            if(s.charAt(left)!=s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    public static void main(String[] args) {
        checkPalindromicSubtring("ababa",3);
        checkPalindromicSubtring("racecar",3);
    }
}
