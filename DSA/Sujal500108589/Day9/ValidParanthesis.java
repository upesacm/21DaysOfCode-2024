import java.util.Stack;

public class ValidParanthesis {
    boolean checkParanthesis(String s){
        Stack<Character> st=new Stack<>();
        for(char ch:s.toCharArray()){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else{
                if(st.isEmpty()){
                    return false;
                }
                char top=st.peek();
                if((ch==')' && top=='(')||(ch=='}' && top=='{')||(ch==']' && top=='[')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.isEmpty();
    }
    public static void main(String[] args) {
        ValidParanthesis obj=new ValidParanthesis();
        Boolean var=obj.checkParanthesis("{[()]}");
        if(var){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }
}
