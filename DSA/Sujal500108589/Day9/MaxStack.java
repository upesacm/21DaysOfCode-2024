import java.util.Stack;

public class MaxStack {
    Stack<Integer> st=new Stack<>();
    Stack<Integer> max=new Stack<>();
    public void push(int x){
        if(st.size()==0){
            st.push(x);
            max.push(x);
        }else{
            st.push(x);
            if(x>max.peek()){
                max.push(x);
            }else{
                max.push(max.peek());
            }
        }
    }
    public void pop(){
        st.pop();
        max.pop();
    }
    public int get_Max(){
        return max.peek();
    }
    public static void main(String[] args) {
        MaxStack s=new MaxStack();
        s.push(1);
        s.push(2);
        System.out.println(s.get_Max());
        s.pop();
        System.out.println(s.get_Max());
    }
}
