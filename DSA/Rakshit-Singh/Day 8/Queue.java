class Queue{
    int queue[];
    int start,end,len;
    Queue(int n){
        queue=new int[n];
        start=0;
        end=0;
        len=n;
    }
    public void push(int num){
        if(end<len){
            queue[end]=num;
            end++;
        }
    }
    public int pop(){
        if(start<end){
            if(start+1==end){
                int t=start;
                start=0;
                end=0;
                return queue[t];
            }
            return queue[start++];
        }
        return -9999;
    }
    public int top(){
        if(start<end){
            return queue[start];
        }
        return -9999;
    }
}