public class Main {
    public static String isPangram(String sentence) {
        boolean[] alphabet = new boolean[26];
        sentence = sentence.toLowerCase();

        for (char c : sentence.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                alphabet[c - 'a'] = true;
            }
        }

        for (boolean b : alphabet) {
            if (!b) {
                return "incomplete";
            }
        }

        return "complete";
    }

    public static void main(String[] args) {
        String sentence = "The quick brown fox jumps over the lazy dog";
        System.out.println(isPangram(sentence));
    }
}
