import java.util.*;
public class palinUsingRec {
    public static boolean palindromeRecursion(String s,int left,int right){
        if(left>=right){
            return true; 
        }
        if(s.charAt(right)!=s.charAt(left)){
            return false;
        }
      
         return palindromeRecursion(s, left+1, right-1);
        // return true;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter a number");
        int n=in.nextInt();
        String s=String.valueOf(n);
        if(palindromeRecursion(s,0,s.length()-1)){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
        in.close();
    }
}
