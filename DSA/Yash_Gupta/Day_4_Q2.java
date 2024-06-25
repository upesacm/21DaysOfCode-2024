//Yash Gupta 500125397
//Assuming all character in word are in lowercase
public class Day_4_Q2 {
    public static void main(String[] args) {
        String test_cases[]={"aabbcc","aabbccc","aabbccssse","acmw","acm","yash"};
        for(int i=0;i<test_cases.length;i++)
        {
            System.out.println(isValid(test_cases[i]));
        }
    }
    public static String isValid(String s) {

        if(s==null){ return "invalid" ;}

        int characterCounts[]= new int[26];

        // Count the frequency of each character
        for (int i=0;i<s.length();i++) {
            characterCounts[s.charAt(i) - 'a']++;
        }

        // Counting frequency of the frequencies
        int frequencyCounts []= new int[s.length() + 1];
        for (int i=0;i<characterCounts.length;i++) {
            if (characterCounts[i] > 0) {
                frequencyCounts[characterCounts[i]]++;
            }
        }

        // Finding the two most common frequencies
        int freq1 = 0, count1 = 0, freq2 = 0, count2 = 0;

        for (int i = 1; i < frequencyCounts.length; i++) {
            if (frequencyCounts[i] > 0) {
                if (freq1 == 0) {
                    freq1 = i;
                    count1 = frequencyCounts[i];
                } else if (freq2 == 0) {
                    freq2 = i;
                    count2 = frequencyCounts[i];
                } else {
                    return "invalid";
                }
            }
        }

        if (freq2 == 0) {
            return "valid";
        }

        // Check if one removal can make the frequencies equal
        if ((count1 == 1 && (freq1 - 1 == freq2 || freq1 - 1 == 0)) || 
            (count2 == 1 && (freq2 - 1 == freq1 || freq2 - 1 == 0))) {
            return "valid";
        }

        return "invalid";
    }
}
 