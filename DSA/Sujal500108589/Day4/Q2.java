import java.util.HashMap;
import java.util.Map;

public class Q2 {
    public static String canBeValid(String s) {
        // Step 1: Count the frequency of each character
        int[] charCount = new int[26];
        for (char c : s.toCharArray()) {
            charCount[c - 'a']++;
        }
        
        // Step 2: Count the frequency of frequencies
        HashMap<Integer, Integer> freqCount = new HashMap<>();
        for (int count : charCount) {
            if (count > 0) {
                freqCount.put(count, freqCount.getOrDefault(count, 0) + 1);
            }
        }

        // Step 3: Analyze the frequency distribution
        if (freqCount.size() == 1) {
            return "valid";  // Only one frequency, already valid
        }

        if (freqCount.size() == 2) {
            // Get the two frequencies and their counts
            int[] freqs = new int[2];
            int[] counts = new int[2];
            int index = 0;
            for (Map.Entry<Integer, Integer> entry : freqCount.entrySet()) {
                freqs[index] = entry.getKey();
                counts[index] = entry.getValue();
                index++;
            }

            // Check if we can remove one character to balance frequencies
            if ((freqs[0] == 1 && counts[0] == 1) || (freqs[1] == 1 && counts[1] == 1)) {
                return "valid"; // One frequency is 1 and it occurs only once
            }
            if ((freqs[0] == freqs[1] + 1 && counts[0] == 1) || (freqs[1] == freqs[0] + 1 && counts[1] == 1)) {
                return "valid"; // One frequency is one more than the other and it occurs only once
            }
        }

        return "invalid";  // Otherwise, it's invalid
    }

    public static void main(String[] args) {
        System.out.println(canBeValid("aabbcc")); 
        System.out.println(canBeValid("aabbc"));   
        System.out.println(canBeValid("aabbccc")); 
        System.out.println(canBeValid("abc"));     
    }
}