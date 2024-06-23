public class Day_1_Q1 {
    public static int countWays(int []candy,int day,int month){
        int count=0;
        for(int i=0;i<=candy.length-month;i++){
            int sum=0;
            for(int j=0;j<month;j++){
                sum+= candy[i+j];
            }
            if(sum==day){
                count++;
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int candy_case_1[]={2, 2, 1, 3, 2};
        int birth_day=4;
        int birth_month=2;
        System.out.println(countWays(candy_case_1,birth_day,birth_month));

        int candy_case_2[]={2, 2, 1, 3, 2};
        birth_day=2;
        birth_month=5;
        System.out.println(countWays(candy_case_2,birth_day,birth_month));

    }
}
