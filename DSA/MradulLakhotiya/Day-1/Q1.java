public class Q1 {

    public static int solution(int day, int month, int[] candy) {
        int count = 0;

        for (int i = 0; i < candy.length - month; i++) {
            int sum = 0;

            for (int j = 0; j < month; j++) {
                sum += candy[i + j];
            }

            if (sum == day) {
                count++;
            }
        }

        return count;
    }
    public static void main(String[] args) {
        int day = 4;
        int month = 2;
        int[] candy = {2, 2, 1, 3, 2};

        int result = solution(day, month, candy);
        System.out.println(result);
    }
}
