import java.util.*;
public class Day3_ques1 {
    public static String isPangram(String sentence){
        sentence=sentence.toLowerCase();

        int[] letterCount=new int[26];

        for (int i=0;i<sentence.length();i++){
            char c=sentence.charAt(i);
            if(c>='a'&&c<='z') {
                int index=c-'a';
                letterCount[index]=1;
            }
        }
        for (int i=0; i<letterCount.length; i++) {
            if (letterCount[i]==0) {
                return "incomplete";
            }
        }
        return "complete";
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a sentence:");
        String sentence=sc.nextLine();
        System.out.println(isPangram(sentence));
    }
    
}
