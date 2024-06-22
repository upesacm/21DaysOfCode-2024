public class que1 {

    public static int Calculate(int[] candy, int day, int month) {
        int count = 0;
        int sum = 0;
        
        for (int i = 0; i < month; i++) {
            sum += candy[i];
        }
        
        if (sum == day) {
            count++;
        }

        for (int i = month; i < candy.length; i++) {
            sum = sum - candy[i - month] + candy[i];  
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
        
        int result = Calculate(candy, day, month);
        System.out.println("Number of ways to divide the bar: " + result);
    }
}
