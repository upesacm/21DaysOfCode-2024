//Yash Gupta 500125397
public class Day_9_Q1 {
    public static void main(String[] args) {
        //test case
        MaxStack stack=new MaxStack(10);
        stack.push(1);
        stack.push(3);
        System.out.println(stack.maxElement);
        stack.pop();
        stack.push(1);
        stack.push(10);
        System.out.println(stack.get_Max());
    }
}

class MaxStack{
    int arr[];
    int top;
    int maxElement;
    MaxStack(int size)
    {
        this.arr=new int[size];
        this.top=-1;
        this.maxElement=Integer.MIN_VALUE;
    }
    void push(int num)
    {
        if(num>maxElement){maxElement=num;}
        this.top++;
        arr[top]=num;
    }
    void pop()
    {
        this.top--;
        maxElement=arr[0];
        for(int i=0;i<=top;i++){if(arr[i]>maxElement){maxElement=arr[i];}}
    }
    int get_Max()
    {
        return maxElement;
    }
}