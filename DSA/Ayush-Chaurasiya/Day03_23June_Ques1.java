import java.util.Scanner;

public class Day03_23June_Ques1 {

    public static void checkPangram(String sentence){
        int freq[] = new int[26];
        for(char c : sentence.toCharArray()){
            if(c==' '){
                continue;
            }
            else{
                c = Character.toLowerCase(c);
                freq[c-'a']++;
            }
        }

        boolean isPangram = true;
        for(int i : freq){
            if(i == 0){
                isPangram = false;
                break;
            }
        }
        if(isPangram){
            System.out.println("Complete");
        }
        else{
            System.out.println("Incomplete");
        }
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the sentence: ");
        String sentence = scanner.nextLine(); 
        scanner.close();

        checkPangram(sentence);
    }
}
