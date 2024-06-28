public class ChocolateBar {

    public static int countWays(int[] candy, int day, int month) {
        int count = 0;
        int n = candy.length;
        
        for (int i = 0; i <= n - month; i++) {
            int sum = 0;
            for (int j = i; j < i + month; j++) {
                sum += candy[j];
            }
            if (sum == day) {
                count++;
            }
        }
        
        return count;
    }

    public static void main(String[] args) {
        int[] candy = {2, 2, 1, 3, 2};
        int day = 4;
        int month = 2;
        
        int ways = countWays(candy, day, month);
        System.out.println("Number of valid ways: " + ways);
    }
}
