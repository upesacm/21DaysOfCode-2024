import java.util.Scanner;

public class Q2 {
    public static void checkSymmetry(String s){
        char ch[]=s.toCharArray();
        if(ch.length%2==1){
            System.out.println("Not Symmetric");
            return;
        }
        int i=0,j=ch.length-1;
        while(i<j){
            if(((int)ch[i])+((int)ch[j])==155){
                i++;j--;
            }else{
                System.out.println("Not Symmetric");
                return;
            }
        }
        System.out.println("Symmetric");
    }
    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      System.out.println("Enter a string:");
      String s=in.next();
      checkSymmetry(s.toUpperCase());
      in.close();
    }
}
