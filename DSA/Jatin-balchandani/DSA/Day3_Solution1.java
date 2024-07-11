import java.util.*;
public class Solution1_Day3 {

    public static String isPangram(String sentence){
        sentence = sentence.toLowerCase();

        Set<Character> alphabetSet = new HashSet<>();
        for(char c= 'a';c <= 'z'; c++){
            alphabetSet.add(c);
        }

        Set<Character> sentenceSet = new HashSet<>();
        for(char c: sentence.toCharArray()){
            if(Character.isLetter(c)){
                sentenceSet.add(c);
            }
        }
        if(sentenceSet.containsAll(alphabetSet)){
            return "Complete";
        }
        else {return "incomplete";}
    }

public static void main(String[] arg){
        String sentence = "The quick brown fox jumps over the lazy dog";
        System.out.println(isPangram(sentence));
}
}
