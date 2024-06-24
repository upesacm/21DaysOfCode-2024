public class PangramChecker {
    public static String checkPangram(String sentence) {
        sentence = sentence.toLowerCase();
        boolean[] letterPresent = new boolean[26];
        for (char c : sentence.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                letterPresent[c - 'a'] = true;
            }
        }
        for (boolean present : letterPresent) {
            if (!present) {
                return "incomplete";
            }
        }
        
        return "complete";
    }
    
    public static void main(String[] args) {
        String sentence = "The quick brown fox jumps over the lazy dog";
        System.out.println(checkPangram(sentence));
    }
}
