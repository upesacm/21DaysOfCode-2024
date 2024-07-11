import java.util.*;
class DAY3_S2 
{
    public static String SymmetricalCheck(String sent)
    {
        StringBuilder stringtoascii=new StringBuilder();
        for(char c:sent.toCharArray())
        {
            stringtoascii.append((int)c);


        }
        String asciiTostring=stringtoascii.toString();
        String reverseAscii=stringtoascii.reverse().toString();

        if(asciiTostring.equals(reverseAscii))
        {
            return "symmetrical";

        }
        else
        {
            return "not symmetrical";
        }
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String enter=sc.nextLine();
        System.out.println(SymmetricalCheck(enter));




    }





}

    
