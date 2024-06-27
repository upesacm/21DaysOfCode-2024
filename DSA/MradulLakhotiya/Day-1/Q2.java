public class Q2 {

    public static int solution(int k, int[] arr) {
        int count = 0;

        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if ((arr[i] + arr[j]) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        int k = 3;
        int[] arr ={1, 3, 2, 6, 1, 2};

        int result = solution(k, arr);
        System.out.println(result);
    }
}
