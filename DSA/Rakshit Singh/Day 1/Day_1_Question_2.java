class Day_1_Question_2{
    public int valid_pairs(int[] arr,int k){
        int len=arr.length;
        int max_count=0;
        for(int x=0;x<=len-2;x++){
            for(int y=x+1;y<len;y++){
                if(arr[x]!=arr[y] && (arr[x]+arr[y])%k==0){
                    max_count++;
                }
            }
        }
        return max_count;
    }
}