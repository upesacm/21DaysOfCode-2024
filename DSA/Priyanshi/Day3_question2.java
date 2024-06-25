import java.util.*;

public class Day3_question2 
{

    public static void Symmetric(String st) 
    {
        int j = 0, i = 0;
        int len = st.length();
        st = st.toLowerCase();
        
        String rev = "";
        char mirrored[] = new char[len];

        for (j = len - 1; j >= 0; j--) 
        {
            rev += st.charAt(j);
        }

        for (i = 0; i < len; i++) {
            char ch = st.charAt(i);
            char mirrorch = ((char) ('z' - (ch - 'a')));
            mirrored[i] = mirrorch;
        }

        String mirroredString = new String(mirrored);

        if (rev.equals(mirroredString)) 
        {
            System.out.println("Symmetric");
        } 
        else 
        {
            System.out.println("Not symmetric");
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String st = "";
        System.out.println("Enter a string: ");
        st = sc.nextLine();

        Symmetric(st);

    }
}
