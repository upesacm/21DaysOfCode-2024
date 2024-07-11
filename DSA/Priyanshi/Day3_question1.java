import java.util.*;

public class Day3_question1 
{
    public static void isPangram(String st)
    {
        boolean[] arr = new boolean[26];
        int index = 0;
        st = st.toLowerCase(); 
        int len = st.length();

        for (int i = 0; i < len; i++)
        {
            if (st.charAt(i) >= 'a' && st.charAt(i) <= 'z')
            {
                index = st.charAt(i) - 'a';
                arr[index] = true;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (!arr[i])
            {
                System.out.println("incomplete");
                return;
            }
        }
        System.out.println("complete");
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string to check pangram string: ");
        String st = sc.nextLine();

        isPangram(st); 
    }
}
