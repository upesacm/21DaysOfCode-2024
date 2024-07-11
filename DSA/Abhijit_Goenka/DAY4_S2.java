public class DAY4_S2 {

    public static void main(String[] args) {
        String string = "aabbcc";
        String result = isValid(string);
        System.out.println(result); 
    }

    public static String isValid(String s) {
        int[] charFrequency = new int[26];
      
        for (char c : s.toCharArray()) {
            charFrequency[c - 'a']++;
        }
       
        int[] frequencyCount = new int[s.length() + 1];
        for (int freq : charFrequency) {
            if (freq > 0) {
                frequencyCount[freq]++;
            }
        }

        int uniqueFrequencies = 0;
        int freq1 = 0, count1 = 0;
        int freq2 = 0, count2 = 0;
        
        for (int i = 1; i <= s.length(); i++) {
            if (frequencyCount[i] > 0) {
                uniqueFrequencies++;
                if (uniqueFrequencies == 1) {
                    freq1 = i;
                    count1 = frequencyCount[i];
                } else if (uniqueFrequencies == 2) {
                    freq2 = i;
                    count2 = frequencyCount[i];
                } else {
                    return "invalid"; 
                }
            }
        }

        if (uniqueFrequencies == 1) 
        {
            
            return "valid";
        } else if (uniqueFrequencies == 2) {
            
            if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
                return "valid";
            } else if (Math.abs(freq1 - freq2) == 1 && (count1 == 1 || count2 == 1)) {
                return "valid";
            }
        }
        
        return "invalid";
    }
}
