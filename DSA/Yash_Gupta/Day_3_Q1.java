//Yash Gupta 500125397
public class Day_3_Q1 {
    public static String isCompleteSentence(String sentence) {
        if(sentence==null)
            return "incomplete";
            
        boolean[] letterPresent = new boolean[26];
        int index;

        // Traversing the sentence
        for (int i=0;i<sentence.length();i++) {
            char ch =sentence.charAt(i);
            if (Character.isLetter(ch)) {
                index = Character.toLowerCase(ch) - 97;
                letterPresent[index] = true;
            }
        }

        // checking if all letters are present
        for (int i=0;i<26;i++) {
            if (!letterPresent[i]) {
                return "incomplete";
            }
        }
        return "complete";
    }

    public static void main(String[] args) {
        //Test case-1
        String s="The quick brown fox jumps over the lazy dog";
        System.out.println(isCompleteSentence(s));

         //Test case-2
         s="This is my day-3 submission";
         System.out.println(isCompleteSentence(s));
    }
}
//time complexity O(n)
//auxillary space O(1)