/**
 * Question 2: 
 * Determine if a string can be rearranged such that all characters have the same frequency. 
 * If one removal can achieve this, return "valid", otherwise return "invalid".
 * 
 * Inputs:
 * A string.
 * 
 * Output:
 * "valid" if the string meets the criteria, otherwise "invalid".
 * 
 * Example:
 * string = "aabbcc"
 * 
 * Output: valid
 */
import java.util.*;
public class Day4_Q2 {
    public static String isValid(String str){
        HashMap<Character,Integer> map = new HashMap<>();
        // for(int i=0;i<str.length();i++){
        //     map.put(str.charAt(i), 0);
        // }
        // for(int i=0;i<str.length();i++){
        //     map.put(str.charAt(i), map.get(str.charAt(i))+1);
        // }
        for(int i=0;i<str.length();i++){
            if(map.containsKey(str.charAt(i))){
                map.put(str.charAt(i), map.get(str.charAt(i))+1);
            }
            else{
                map.put(str.charAt(i), 1);
            }
        }
        // System.out.println(map);
        HashSet<Integer> set = new HashSet<>(map.values());
        // System.out.println(set);
        if(set.size()==1){
            return "valid";
        }
        else if(set.size()==2){
            HashMap<Integer,Integer> map2 = new HashMap<>();
            for(Map.Entry<Character,Integer> entry : map.entrySet()){    
                if(map2.containsKey(entry.getValue())){
                    map2.put(entry.getValue(), map2.get(entry.getValue())+1);
                }
                else{
                    map2.put(entry.getValue(), 1);
                }
            }  
            // System.out.println(map2);
            Integer [] arr = set.toArray(new Integer[0]);
            // int diff=Math.abs(arr[0]-arr[1]);
            int diff = map2.get(arr[0])>map2.get(arr[1])?arr[1]-arr[0]:arr[0]-arr[1];
            if(map.containsValue(1) && map2.get(1)==1){
                return "valid";
            }
            else if(map2.containsValue(1) && diff == 1){
                return "valid";
            }
        }
        return "invalid";
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        System.out.println("The string is: " + isValid(str));
    }
}
