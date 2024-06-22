package DSA.Nizaul_Rahman;

public class Day1Q1 {

    public static void main(String[] args) {
        int[] candy = {2, 2, 1, 3, 2};
        int day = 4;
        int month = 2;

        int result = birthdayChocolate(candy, day, month);
        System.out.println("Number of valid ways to divide the bar: " + result);
    }

    public static int birthdayChocolate(int[] chocolate, int day, int month) {
        int ways = 0;
        int n = chocolate.length;

        if (month > n || (month == n && day > 0)) {
            return 0; // if month is larger than chocolate length or no way if month is equal to chocolate length
        }
        
        // Iterate through the chocolate array
        for (int i = 0; i <= n - month; i++) {
            int sum = 0;
            
            // Calculate the sum of the segment of length 'month'
            for (int j = i; j < i + month; j++) {
                sum += chocolate[j];
            }
            
            // Check if the sum matches the day
            if (sum == day) {
                ways++;
            }
        }

        return ways;
    }
}
