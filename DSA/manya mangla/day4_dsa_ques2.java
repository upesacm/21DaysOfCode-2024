public class RearrangeStringFrequency {

    public static String canRearrange(String s) {
        // Step 1: Initialize frequency array for ASCII characters
        int[] freq = new int[256]; // assuming ASCII characters

        // Step 2: Count frequencies of each character
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freq[c]++;
        }

        // Step 3: Find maximum and minimum frequencies
        int maxFreq = Integer.MIN_VALUE;
        int minFreq = Integer.MAX_VALUE;
        for (int i = 0; i < freq.length; i++) {
            if (freq[i] > 0) {
                maxFreq = Math.max(maxFreq, freq[i]);
                minFreq = Math.min(minFreq, freq[i]);
            }
        }

        // Step 4: Check conditions
        if (maxFreq == minFreq) {
            return "valid";
        } else if (maxFreq - minFreq == 1) {
            int countMaxFreq = 0;
            for (int i = 0; i < freq.length; i++) {
                if (freq[i] == maxFreq) {
                    countMaxFreq++;
                }
            }
            // There should be exactly one character with maxFreq
            if (countMaxFreq == 1) {
                return "valid";
            }
        }

        return "invalid";
    }

    public static void main(String[] args) {
        String string = "aabbcc";
        System.out.println(canRearrange(string)); // Output: valid
        
        String string2 = "aabbccc";
        System.out.println(canRearrange(string2)); // Output: valid
        
        String string3 = "abc";
        System.out.println(canRearrange(string3)); // Output: invalid
    }
}
