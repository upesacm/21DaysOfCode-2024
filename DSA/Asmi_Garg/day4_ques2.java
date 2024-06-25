import java.util.Scanner;

public class SameFrequencyChecker {

    public static String isValid(String s) {
        int[] charCount = new int[26];
        for (char c : s.toCharArray()) {
            charCount[c - 'a']++;
        }

        int[] frequencyCount = new int[s.length() + 1];
        for (int count : charCount) {
            if (count > 0) {
                frequencyCount[count]++;
            }
        }

        int uniqueFreqCount = 0;
        int[] uniqueFreq = new int[2];
        int[] freqOccurrences = new int[2];

        for (int i = 1; i < frequencyCount.length; i++) {
            if (frequencyCount[i] > 0) {
                uniqueFreq[uniqueFreqCount] = i;
                freqOccurrences[uniqueFreqCount] = frequencyCount[i];
                uniqueFreqCount++;
            }
        }

        if (uniqueFreqCount == 1) {
            return "valid";
        }

        if (uniqueFreqCount == 2) {
            int freq1 = uniqueFreq[0];
            int freq2 = uniqueFreq[1];
            int count1 = freqOccurrences[0];
            int count2 = freqOccurrences[1];

            if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
                return "valid";
            }

            if ((Math.abs(freq1 - freq2) == 1) && ((freq1 > freq2 && count1 == 1) || (freq2 > freq1 && count2 == 1))) {
                return "valid";
            }
        }

        return "invalid";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String input = scanner.nextLine();
        System.out.println(isValid(input));
        scanner.close();
    }
}
