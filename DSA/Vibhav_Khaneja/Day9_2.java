import java.util.*;
public class Day9_2 {
public static boolean Is_equal(String s) {
        Stack<Character> st = new Stack<Character>();
        for (char it : s.toCharArray()) {
            if (it == '(' || it == '[' || it == '{')
                st.push(it);
            else {
                if(st.isEmpty()) return false;
                char ch = st.pop(); 
                if((it == ')' && ch == '(') ||  (it == ']' && ch == '[') || (it == '}' && ch == '{')) continue;
                else return false;
            }
        }
        return st.isEmpty();
    }

 public static void main (String[] args) {
		
		String s="{[()]}";
		if(Is_equal(s)==true)
		System.out.println("YES");
		else
		System.out.println("NO");
	}
}