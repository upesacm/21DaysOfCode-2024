class MyStack {
    private int[] stackArray;
    private int top;
    private int capacity;

    public MyStack(int capacity) {
        this.capacity = capacity;
        this.stackArray = new int[capacity];
        this.top = -1;
    }

    public void push(int item) {
        if (top == capacity - 1) {
            System.out.println("Stack is full");
            return;
        }
        stackArray[++top] = item;
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return stackArray[top--];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public int findMax(){
        int max=0;
        int temp[] = new int[top+1];
        int len = temp.length;
        for(int i=0;i<len;i++){
            temp[i]=pop();
            if(temp[i]>max){
                max=temp[i];
            }
        }
        for(int i=0;i<len;i++){
            push(temp[len-i-1]);
        }
        return max;
    }

    public void displayStack(){
        for(int i=0;i<=top;i++){
            System.out.print(stackArray[i]+" ");
        }
    }
}

public class Day09_29June_Ques1{

    public static void main(String[] args) {
        MyStack stack = new MyStack(5);
        stack.push(1);
        stack.push(2);        
        System.out.println("Max element is "+stack.findMax());
        
        stack.pop();
        System.out.println("Max element is "+stack.findMax());
    }
}  
