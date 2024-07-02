public class Day12_02July_Ques1{

    public static int fibonacci(int n){
        if(n == 0 || n == 1){
            return n;
        }
        else{
            return fibonacci(n-1) + fibonacci(n-2);
        }
    }

    public static void main(String[] args) {
        int n = 5;
        System.out.println(fibonacci(n));
    }
}
