class Day_1_Question_1{
    public int max_number_of_ways(int[] candy,int day,int month){
        int len=candy.length;
        int ways=0;
        
        for(int x=0;x<len-month;x++)
        {
            int count=0;
            for(int y=0;y<month;y++){
                count+=candy[x+y];
            }
            if(count==day){
                ways++;
            }
        }
        return ways;
    }
}