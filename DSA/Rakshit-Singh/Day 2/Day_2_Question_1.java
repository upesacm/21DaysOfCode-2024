class Day_2_Question_1
{
    public String Class(int threshold,int[] arrival_times){
        int count=0;
        for(int x=0;x<arrival_times.length;x++){
            if(arrival_times[x]<0){
                count+=arrival_times[x]*-1;
            }
        }
        if(count>=threshold){
            return "YES";
        }
        return "NO";
    }
}