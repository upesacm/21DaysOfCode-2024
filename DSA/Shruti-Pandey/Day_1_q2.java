import java.util.HashMap;

public class DivisiblePairsCount {
    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 6, 1, 2};
        int k = 3;
        
        int count = countPairs(arr, k);
        
        System.out.println("Number of valid pairs: " + count);
    }
    
    public static int countPairs(int[] arr, int k) {
        
        HashMap<Integer, Integer> remainderMap = new HashMap<>();
        int count = 0;

        for (int i = 0; i < arr.length; i++) {
            int remainder = arr[i] % k;
            
            if (remainder < 0) {
                remainder += k; 
            }
            
            if (remainderMap.containsKey((k - remainder) % k)) {
                count += remainderMap.get((k - remainder) % k);
            }
            remainderMap.put(remainder, remainderMap.getOrDefault(remainder, 0) + 1);
        }
        
        return count;
    }
}
