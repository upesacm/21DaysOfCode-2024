public class Day_1_Question_2 {
    public static int validPairs(int arr[], int k) {
        int validPairCount = 0;
        for (int i=0; i < arr.length; ++i) {
            for (int j=0; j < arr.length; j++) {
                if (arr[i] < arr[j] && (arr[i] + arr[j]) % k == 0)
                    ++validPairCount;
            }
        }
        
        return validPairCount;
    }
    
    public static void main(String[] args) {
        int arr[] = {1, 3, 2, 6, 1, 2};
        System.out.println(validPairs(arr, 3));
    }
}
