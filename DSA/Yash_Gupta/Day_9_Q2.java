public class Day_9_Q2{
    public static String validParenthesis(String s){
        Stack stack=new Stack(s.length());
        for (int i=0;i<s.length();i++) {
            char c=s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.isEmpty()) {
                    return "NO";
                }
                char top = stack.pop();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                    return "NO";
                }
            }
        }

        return (stack.isEmpty())?"YES":"NO";
    }
    public static void main(String args[]){
        String test1 = "()";
        String test2 = "(())";
        String test3 = "(()))";
        String test4 = "(()";
        String test5 = "{}[]()";
        String test6 = "{[()]}";
        String test7 = "{[(])}";
        String test8 = "a(b)c";
        String test9 = "a{b(c)d}e";
        String test10 = "[a+b]*(c+d)";
        String test11 = "a+(b*c)-2-a";
        String test12 = "a(b+c{d[e]f}g)h";

        System.out.println(validParenthesis(test1));  
        System.out.println(validParenthesis(test2));  
        System.out.println(validParenthesis(test3));  
        System.out.println(validParenthesis(test4));  
        System.out.println(validParenthesis(test5));  
        System.out.println(validParenthesis(test6));  
        System.out.println(validParenthesis(test7));  
        System.out.println(validParenthesis(test8));  
        System.out.println(validParenthesis(test9)); 
        System.out.println(validParenthesis(test10));
        System.out.println(validParenthesis(test11));
        System.out.println(validParenthesis(test12)); 
    }
}

class Stack{
    int top;
    int size;
    char a[];
    Stack(int size)
    {
        a=new char[size];
        this.size=size;
        this.top=-1;
    }
    boolean isEmpty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }
    boolean isFull()
    {
        if(top==size-1)
        return true;
        else
        return false;
    }
    void push(char ch)
    {
        if(isFull())
        {
            System.out.println("Stack is full");
        }else{
            top++;
            a[top]=ch;
        }
    }
    char pop()
    {
        if(isEmpty())
        {
            System.out.println("Stack is empty");
            return '\0';
        }
        else{
            top--;
            return a[top+1];
        }
    }

}
//time complexity O(n)
//auxillary space O(n)