import java.util.*;

class Day_8_Question_1 {
    public static int sum(int arr[]) {
        int sum = 0;
        for (int i: arr)
            sum += i;
        return sum;
    }
    
    public static int pop(int stack[]) {
        int temp = stack[0];
        for (int i=0; i < stack.length-1; i++)
            stack[i] = stack[i+1];
        stack[stack.length-1] = 0;
        return temp;
    }
    
    public static int maxHeight(int stack1[], int stack2[], int stack3[]) {
        int min = Math.min(Math.min(sum(stack1), sum(stack2)), sum(stack3));
        while (sum(stack1) > min)
            pop(stack1);
        
        while (sum(stack2) > min)
            pop(stack2);
        
        while (sum(stack3) > min)
            pop(stack3);
        
        if (sum(stack1) == sum(stack2) && sum(stack2) == sum(stack3))
            return sum(stack1);
        
        return maxHeight(stack1, stack2, stack3);
    }
    public static void main(String[] args) {
        int []stack1 = {3, 2, 1, 1, 1};
        int []stack2 = {4, 3, 2};
        int []stack3 = {1, 1, 4, 1};
        
        System.out.println(maxHeight(stack1, stack2, stack3));
    }
}