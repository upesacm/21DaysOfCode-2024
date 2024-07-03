import java.util.*;

public class fibo {
    public static int fib(int n){
        if(n==0)return 0;
        else if(n==1) return 1;
        else return fib(n-1)+fib(n-2); 
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter nth number ");
        int n=in.nextInt();
        int k=fib(n);
        System.out.println(k+" " +"is the nth fibonnaci number");
        in.close();
    }
}
