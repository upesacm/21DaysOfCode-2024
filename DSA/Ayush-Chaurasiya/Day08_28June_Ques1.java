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

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return stackArray[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public int size() {
        return top + 1;
    }

    public int stackSum() {
        int sum = 0;
        for (int i = 0; i <= top; i++) {
            sum += stackArray[i];
        }
        return sum;
    }
}

public class Day08_28June_Ques1 {

    public static void main(String[] args) {
        MyStack stack1 = new MyStack(5);
        stack1.push(1);
        stack1.push(1);
        stack1.push(1);
        stack1.push(2);
        stack1.push(3);
        
        MyStack stack2 = new MyStack(3);
        stack2.push(2);
        stack2.push(3);
        stack2.push(4);
        
        MyStack stack3 = new MyStack(4);
        stack3.push(1);
        stack3.push(4);
        stack3.push(1);
        stack3.push(1);

        int maxEqualHeight = getMaxEqualHeight(stack1, stack2, stack3);
        System.out.println(maxEqualHeight);
    }

    public static int getMaxEqualHeight(MyStack stack1, MyStack stack2, MyStack stack3) {
        int sum1 = stack1.stackSum();
        int sum2 = stack2.stackSum();
        int sum3 = stack3.stackSum();

        while (true) {
            if (sum1 == sum2 && sum1 == sum3) {
                return sum1;
            }

            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= stack1.pop();
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= stack2.pop();
            } else if (sum3 >= sum1 && sum3 >= sum2) {
                sum3 -= stack3.pop();
            }
        }
    }
}
