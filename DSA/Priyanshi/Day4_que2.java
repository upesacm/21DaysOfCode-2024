import java.util.Scanner;

public class Day4_que2 {

    public static int[] freqcount(String s) {
        int[] freq = new int[26]; 

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            freq[ch - 'a']++;
        }

        return freq;
    }

    // Method to check if the string can be rearranged such that all characters have the same frequency
    public static void checkStringValidity(String s) {
        s = s.toLowerCase();
        int[] freq = freqcount(s);

        // Count the frequency of frequencies
        int[] freqCount = new int[s.length() + 1];
        for (int f : freq) {
            if (f > 0) {
                freqCount[f]++;
            }
        }

        int distinctFreqCount = 0;
        for (int count : freqCount) {
            if (count > 0) {
                distinctFreqCount++;
            }
        }

        if (distinctFreqCount == 1) {
            System.out.println("valid");
        } else if (distinctFreqCount == 2) {
            int freq1 = 0, freq2 = 0, count1 = 0, count2 = 0;

            for (int i = 0; i < freqCount.length; i++) {
                if (freqCount[i] > 0) {
                    if (freq1 == 0) {
                        freq1 = i;
                        count1 = freqCount[i];
                    } else {
                        freq2 = i;
                        count2 = freqCount[i];
                    }
                }
            }

            if ((count1 == 1 && (freq1 == 1 || freq1 - 1 == freq2)) ||
                (count2 == 1 && (freq2 == 1 || freq2 - 1 == freq1))) {
                System.out.println("valid");
            } else {
                System.out.println("invalid");
            }
        } else {
            System.out.println("invalid");
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String st = "";

        System.out.println("Enter a string: ");
        st = sc.nextLine();

        checkStringValidity(st);
    }
}
