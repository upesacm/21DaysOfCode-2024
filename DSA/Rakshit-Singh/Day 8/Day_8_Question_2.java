import java.util.Scanner;
class Day_8_Question_2
{
    Queue q1,q2;
    int start;
    public Day_8_Question_2(int n){
        q1=new Queue(n);
        q2=new Queue(n);
        start=0;
    }

    public void push(int num){
        int x;

        for(x=0;x<start;x++){
            int a=q1.pop();
            q2.push(a);
        }

        q1.push(num);
        start++;
        for(int y=0;y<x;y++){
            int a=q2.pop();
            q1.push(a);
        }
    }

    public int pop(){
        return q1.pop();
    }

    public int top(){
        return q1.top();
    }

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter size of stack : ");
        int size=sc.nextInt();

        Day_8_Question_2 stack = new Day_8_Question_2(size);

        stack.push(1);
        stack.push(2);

        System.out.println(stack.top());
        System.out.println(stack.pop());
        System.out.println(stack.top());
    }
}