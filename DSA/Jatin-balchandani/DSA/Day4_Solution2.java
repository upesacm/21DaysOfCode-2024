    import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

    public class Solution2_Day4 {

        public static String isValid(String s) {
            Map<Character, Integer> charCount = new HashMap<>();

            // Step 1: Count the frequency of each character
            for (char c : s.toCharArray()) {
                charCount.put(c, charCount.getOrDefault(c, 0) + 1);
            }

            // Step 2: Count the frequency of these frequencies
            Map<Integer, Integer> frequencyCount = new HashMap<>();
            for (int freq : charCount.values()) {
                frequencyCount.put(freq, frequencyCount.getOrDefault(freq, 0) + 1);
            }

            if (frequencyCount.size() == 1) {
                // All characters have the same frequency
                return "valid";
            }

            if (frequencyCount.size() == 2) {
                int freq1 = (int) frequencyCount.keySet().toArray()[0];
                int freq2 = (int) frequencyCount.keySet().toArray()[1];
                int count1 = frequencyCount.get(freq1);
                int count2 = frequencyCount.get(freq2);

                // Check if one frequency is 1 and the character with this frequency can be removed
                if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
                    return "valid";
                }

                // Check if the frequencies differ by 1 and one of them appears only once
                if ((Math.abs(freq1 - freq2) == 1) && ((count1 == 1) || (count2 == 1))) {
                    return "valid";
                }
            }

            return "invalid";
        }

        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter a string: ");
            String input = scanner.nextLine();
            scanner.close();

            System.out.println(isValid(input));
        }
    }


