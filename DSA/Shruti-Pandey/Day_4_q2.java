import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CharacterFrequencyValidator {
    public static String isValid(String s) {
        if (s == null || s.isEmpty()) {
            return "invalid";
        }

        Map<Character, Integer> frequencyMap = new HashMap<>();
        
        for (char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        Map<Integer, Integer> frequencyCount = new HashMap<>();
        
        for (int freq : frequencyMap.values()) {
            frequencyCount.put(freq, frequencyCount.getOrDefault(freq, 0) + 1);
        }

        if (frequencyCount.size() == 1) {
            return "valid";
        }

        if (frequencyCount.size() > 2) {
            return "invalid";
        }

        int[] freqs = new int[2];
        int[] counts = new int[2];
        int i = 0;
        for (Map.Entry<Integer, Integer> entry : frequencyCount.entrySet()) {
            freqs[i] = entry.getKey();
            counts[i] = entry.getValue();
            i++;
        }

        if ((freqs[0] == 1 && counts[0] == 1) || (freqs[1] == 1 && counts[1] == 1)) {
            return "valid";
        }
        if ((Math.abs(freqs[0] - freqs[1]) == 1) && 
            ((freqs[0] > freqs[1] && counts[0] == 1) || (freqs[1] > freqs[0] && counts[1] == 1))) {
            return "valid";
        }

        return "invalid";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the string: ");
        String input = scanner.nextLine();
        
        String result = isValid(input);
        System.out.println("Result: " + result);
        
        scanner.close();
    }
}
