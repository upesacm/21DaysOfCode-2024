import java.util.*;

public class PairCounter {

    public static int countPairs(List<Integer> arr, int k) {
        Map<Integer, Integer> remainderCount = new HashMap<>();
        for (int num : arr) {
            int remainder = num % k;
            remainderCount.put(remainder, remainderCount.getOrDefault(remainder, 0) + 1);
        }

        int count = 0;

        for (Map.Entry<Integer, Integer> pair : remainderCount.entrySet()) {
            int remainder = pair.getKey();
            int complement = (k - remainder) % k;

            if (remainder == complement) {
                count += pair.getValue() / 2;
            } else {
                if (remainderCount.containsKey(complement)) {
                    count += Math.min(pair.getValue(), remainderCount.get(complement));
                    remainderCount.put(complement, 0); // Ensures pairs are not counted multiple times
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(1, 3, 2, 6, 1, 2);
        int k = 3;
        System.out.println(countPairs(arr, k));
    }
}
