
public class Q2 {
    public static String solution(String input) {
        int[] frequency = new int[26];
        char[] input_array = input.toCharArray();
        boolean removed_char = false;

        for (char ch : input_array) {
            frequency[ch - 'a']++;
        }

        for (int i = 1; i < frequency.length; i++) {

            if (frequency[i-1] == 0 || frequency[i] == 0) {
                continue;
            }

            if (frequency[i-1] != frequency[i]) {

                if (!removed_char) {

                    if (frequency[i-1] > frequency[i]) {
                        frequency[i-1]--;
                    }
                    else {
                        frequency[i]--;
                    }

                    removed_char = true;
                }
                else {
                    return "invalid";
                }
            }
        }
        return "valid";
    }
    public static void main(String[] args) {
        String input = "aabbcc";
        String result = solution(input);
        System.out.println(result);
    }
}
