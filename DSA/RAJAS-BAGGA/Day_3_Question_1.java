import java.util.HashSet;

public class Day_3_Question_1 {
    public static String isComplete(String str) {
        str = str.toLowerCase();
        HashSet<Character> seen = new HashSet<>();
        
        for (char c: str.toCharArray())
            if (c >= 'a' && c <='z')
                seen.add(c);
        
        
        return (seen.size() == 26)? "complete": "incomplete";
    }
    public static void main(String[] args) {
        System.out.println(isComplete("Amazingly few discotheques provide jukeboxes"));
        System.out.println(isComplete("The quick brown fox jumps over the lazy dog?//....,,"));
        System.out.println(isComplete("lol"));
    }
}
