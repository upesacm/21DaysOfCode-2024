public class Q2 {
    public static String solution(String input) {
        char[] reverse_alphabet = {
            'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 
            'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 
            'f', 'e', 'd', 'c', 'b', 'a'
        };
        StringBuilder revers_ASCII = new StringBuilder(input.length());

        for (char ch : input.toCharArray()) {
            revers_ASCII.append(reverse_alphabet[ch - 'a']);
        }

        String finial_result = revers_ASCII.reverse().toString();

        if (input.equals(finial_result)) {
            return "symmetrical";
        }
        else {
            return "not symmetrical";
        }
    }
    public static void main(String[] args) {
        String input = "acxz";
        String result = solution(input);
        System.out.println(result);
    }
}
