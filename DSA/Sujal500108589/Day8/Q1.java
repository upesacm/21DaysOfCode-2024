import java.util.Stack;

public class Q1 {
    public static int maxEqualHeight(int[] stack1, int[] stack2, int[] stack3){
        int h1=0,h2=0,h3=0;
        for(int e: stack1){
            h1+=e;
        }
        for(int e: stack2){
            h2+=e;
        }
        for(int e: stack3){
            h3+=e;
        }
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        Stack<Integer> s3 = new Stack<>();
        for(int i=stack1.length-1;i>=0;i--){
            s1.push(stack1[i]);
        }
        for(int i=stack2.length-1;i>=0;i--){
            s2.push(stack2[i]);
        }
        for(int i=stack3.length-1;i>=0;i--){
            s3.push(stack3[i]);
        }
        while(true){
            if(h1==h2 && h2==h3){
                return h1;
            }
            if(h1>=h2 && h1>=h3) h1-=s1.pop();
            else if(h2>=h3 && h2>=h1) h2-=s2.pop();
            else if(h3>=h2 && h3>=h1) h3-=s3.pop();
        }
    }
    public static void main(String[] args) {
        int[] stack1 = {3, 2, 1, 1, 1};
        int[] stack2 = {4, 3, 2};
        int[] stack3 = {1, 1, 4, 1};

        int result = maxEqualHeight(stack1, stack2, stack3);
        System.out.println("Maximum possible height where all stacks are equal: " + result);  // Output: 5
    }
}
