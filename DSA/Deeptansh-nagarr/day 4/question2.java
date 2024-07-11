import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        String str = "aabbcc";
        System.out.println(canBeRearranged(str));
    }

    public static String canBeRearranged(String str) {
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : str.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        int maxFreq = 0;
        int minFreq = Integer.MAX_VALUE;
        int countMaxFreq = 0;
        int countMinFreq = 0;

        for (int freq : freqMap.values()) {
            if (freq > maxFreq) {
                maxFreq = freq;
                countMaxFreq = 1;
            } else if (freq == maxFreq) {
                countMaxFreq++;
            }

            if (freq < minFreq) {
                minFreq = freq;
                countMinFreq = 1;
            } else if (freq == minFreq) {
                countMinFreq++;
            }
        }
      
        if (maxFreq == minFreq) {
            return "valid";
        } else if (maxFreq - minFreq == 1 && countMaxFreq == 1) {
            return "valid";
        } else {
            return "invalid";
        }
    }
}
