import java.util.HashMap;
import java.util.Map;

public class RearrangeString {
    public static String rearrangeString(String str) {
        Map<Character, Integer> freqMap = new HashMap<>();

        for (char c : str.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        int maxFreq = 0;
        int minFreq = str.length();
        int countMaxFreq = 0;

        for (int freq : freqMap.values()) {
            maxFreq = Math.max(maxFreq, freq);
            minFreq = Math.min(minFreq, freq);
            if (freq == maxFreq) {
                countMaxFreq++;
            }
        }

        if (maxFreq > (str.length() + 1) / 2) {
            return "invalid";
        }

        if (maxFreq == minFreq) {
            return "valid";
        }

        if (maxFreq - minFreq > 1) {
            return "invalid";
        }

        if (countMaxFreq > 1) {
            return "invalid";
        }

        return "valid";
    }

    public static void main(String[] args) {
        String str = "aabbcc";

        System.out.println("Rearrangement validity: " + rearrangeString(str));
    }
}
