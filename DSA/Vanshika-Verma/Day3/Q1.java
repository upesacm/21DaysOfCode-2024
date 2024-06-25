import java.util.Scanner;

public class Pangram {
    public static String check(String sent, int len) {
       
        int c=0;
        for(int i = 97; i<= 122; ++i){
            for(int j=0; j <len; j++){
                char ch = sent.charAt(j);
                if(i==(int)ch){
                    c++;
                    break;}
                    else
                    continue;
                    
                }
            }
            if (c==26)
            return "complete";
            else
            return "incomplete";

        }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a sentence:");
        String sent = sc.nextLine();
        String s = sent.toLowerCase();
        int len =sent.length();
        System.out.println(check(s, len));
    }
}
 
