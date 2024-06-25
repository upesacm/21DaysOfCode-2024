
/*
##### Output: 2

**Question 2:** Determine if a string can be rearranged such that 
all characters have the same frequency. If one removal can achieve this, return "valid", 
otherwise return "invalid".

##### Inputs:
- A string.
##### Output:
- "valid" if the string meets the criteria, otherwise "invalid".
##### Example:

string = "aabbcc"

##### Output: valid
 */
import java.util.*;
public class dayFour_Question2 {
    public static void main (String args[]){
        String str= "aabbcc";
       System.out.println( getRes(str));
    }
    private static String getRes(String str){
        HashMap<Character, Integer> mp = new HashMap<>();
        for (char ch : str.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }
        Set<Integer> set = new HashSet<>(mp.values());
        if(set.size()>2){
            return "invalid";
        }
            if (set.size() > 2) {
                return "invalid";
            } else {
                int maxi = Integer.MIN_VALUE;
                int mini = Integer.MAX_VALUE;
                for (int val : mp.values()) {
                    maxi = Math.max(val, maxi);
                    mini = Math.min(val, mini);
                }
    
            if(maxi-mini<=1) return "valid";
            else return "invalid";

        }
    }
    
}
