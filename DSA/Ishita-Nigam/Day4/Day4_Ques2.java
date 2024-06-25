import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Day4_Ques2 {

    public static String isValid(String input) {
        int[] charFreq = new int[26];

        // frequency of each character
        for (char c : input.toCharArray()) {
            charFreq[c - 'a']++;
        }

        //number of different frequencies
        Map<Integer, Integer> freqCount = new HashMap<>();
        for (int freq : charFreq) {
            if (freq > 0) {
                freqCount.put(freq, freqCount.getOrDefault(freq, 0) + 1);
            }
        }

        // only 1 frequency, allready valid
        if (freqCount.size() == 1) {
            return "valid";
        }

        // frequency > 2,  it's invalid, since wee only removing 1 character
        if (freqCount.size() > 2) {
            return "invalid";
        }

        // exactly 2 different frequencies
        int freq1 = (int) freqCount.keySet().toArray()[0];
        int freq2 = (int) freqCount.keySet().toArray()[1];
        int count1 = freqCount.get(freq1);
        int count2 = freqCount.get(freq2);

        int higherFreq = Math.max(freq1, freq2);
        int lowerFreq = Math.min(freq1, freq2);

        // Check if its possible to make the string valid by one removal
        if ((count1 == 1 && (higherFreq - 1 == lowerFreq || higherFreq - 1 == 0)) || (count2 == 1 && (lowerFreq == 1))) {
            return "valid";
        }

        return "invalid";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String input = scanner.nextLine();
        scanner.close();

        System.out.println(isValid(input));
    }
}