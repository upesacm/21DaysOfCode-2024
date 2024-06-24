public class Q1 {
    public static String solution(String input) {
        int[] counter = new int[26];

        char[] input_lower = input.toLowerCase().replaceAll("\\s+", "").toCharArray();

        for (char ch : input_lower) {
            counter[ch - 'a']++;
        }

        for (int i : counter) {
            if (i == 0) {
                return "incomplete";
            }
        }

        return "complete";
    }
    public static void main(String[] args) {
        String input = "The quick brown fox jumps over the lazy dog";
        String result = solution(input);
        System.out.println(result);
    }
}
