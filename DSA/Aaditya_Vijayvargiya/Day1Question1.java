// Day1Question1Raju have a candy where each square has a number. Rohan wants to find out how many ways she can break the bar into a contiguous segment such that:

// 1. The segment length matches Raju's birth month.
// 2. The sum of the numbers in the segment equals Raju's birth day.


    public static int segment(int[]arr, int month, int day){
        int segmentSize=month;
        int i,j;
        int sum=0;
        int count=0;
        for(i=0;i<=arr.length-segmentSize;i++){
            sum=0;
            for(j=i;j<i+segmentSize;j++){
                sum+=arr[j];
            }
            if(sum==day){
                count+=1;
                
            }
        }
        return count;
    }
