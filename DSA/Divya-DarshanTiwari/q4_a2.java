import java.util.*;
import java.util.Map.Entry;

public class q4_a2 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Give me the word");
        String word = sc.nextLine();

        String val_not = valid_Not(word);

        System.out.println(val_not);

        sc.close();

    }

    public static String valid_Not(String word) {
        int len = word.length();
        HashMap<Character, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> map_map = new HashMap<>();

        for (int i = 0; i < len; i++) {
            char ch = word.charAt(i);
            if (map.containsKey(ch)) {
                int value = map.get(ch);
                map.put(ch, value + 1);
            } else {
                map.put(ch, 1);
            }
        }
        for (Map.Entry<Character, Integer> e : map.entrySet()) {
            int x = e.getValue();
            if (map_map.containsKey(x)) {
                map_map.put(x, x + 1);
            } else {
                map_map.put(x, 1);
            }
        }

        boolean condition1 = map_map.size() == 1;
        boolean condition2 = map_map.size() == 2;

        if (condition1) {
            return "valid";
        } else if (condition2) {
            int max = 0, min = Integer.MAX_VALUE;
            int maxCount = 0, minCount = 0;
            for (Map.Entry<Integer, Integer> e : map_map.entrySet()) {
                int key = e.getKey();
                int value = e.getValue();
                if (key > max) {
                    max = key;
                    maxCount = value;
                }
                if (key < min) {
                    min = key;
                    minCount = value;
                }
            }
            if ((max - min == 1 && maxCount == 1) || (min == 1 && minCount == 1)) {
                return "valid";
            } else if (maxCount == 1 && max - 1 == min) {
                return "valid";
            } else if (minCount == 1 && min + 1 == max) {
                return "valid";
            } else {
                return "not valid";
            }
        } else {
            return "not valid";
        }
    }

}