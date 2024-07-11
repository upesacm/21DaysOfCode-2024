import java.util.*;

public class Day_4_Question_2 {
    public static String isFrequenciallyValid(String str) {
        str = str.replaceAll(" ", "");
        HashMap<Character, Integer> seen = new HashMap<Character, Integer>();

        for (char i : str.toCharArray())
            seen.put(i, seen.getOrDefault(i, 0) + 1);

        List<Integer> frequencies = new ArrayList<Integer>();
        for (int i : seen.values())
            frequencies.add(i);

        Collections.sort(frequencies);

        boolean alter = false;
        for (int i = 1; i < frequencies.size(); i++) {
            if (frequencies.get(i) - frequencies.get(i - 1) > 1)
                return "invalid";

            else if (!alter && frequencies.get(i) - frequencies.get(i - 1) == 1) {
                frequencies.set(i, frequencies.get(i) - 1);
                alter = true;
            } else if (alter && frequencies.get(i) != frequencies.get(i - 1))
                return "invalid";
        }
        return "valid";

    }

    public static void main(String[] args) {
        System.out.println(isFrequenciallyValid("aabbcc"));
    }
}
