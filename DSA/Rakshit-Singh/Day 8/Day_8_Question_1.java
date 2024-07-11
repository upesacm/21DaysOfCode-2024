class Day_8_Question_1
{
    public int sum(int[] ar,int start,int end){
        int total=0;
        for(int x=start;x<end;x++){
            total+=ar[x];
        }
        return total;
    }
    public int max_height(int[] ar1,int[] ar2,int[] ar3){
        int equal_height=0;
        int start1=0,start2=0,start3=0;
        int end1=ar1.length,end2=ar2.length,end3=ar3.length;
        while(true){
            int sum1=sum(ar1,start1,end1);
            int sum2=sum(ar2,start2,end2);
            int sum3=sum(ar3,start3,end3);
            
            if(sum1==sum2 && sum2==sum3){
                equal_height=sum1;
                break;
            }
            else{
                if(sum1>sum2 && sum1>sum3){
                    start1++;
                }
                else if(sum2>sum1 && sum2>sum3){
                    start2++;
                }
                else{
                    start3++;
                }
            }
            
            if(start1==end1 || start2==end2 || start3==end3){
                break;
            }
        }
        return equal_height;
    }
}