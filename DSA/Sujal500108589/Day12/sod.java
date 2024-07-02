import java.util.*;
public class sod {
    public static int sumOfDigits(int num){
        if(num==0)return 0;
        else return (num%10)+sumOfDigits(num/10);
    }
    public static int findSumUntilSingleDigit(int n){
       while(n>=10){
        n=sumOfDigits(n);
       }
       return n;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter number");
        int n=in.nextInt();
        int ans=findSumUntilSingleDigit(n);
        System.out.println("Sum of digits:"+ans);
        in.close();
    }
}