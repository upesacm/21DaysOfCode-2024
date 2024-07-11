//Yash Gupta 500125397
public class Day_3_Q2 {
    public static String isSymmetrical(String word)
    {
        if(word==null){return "unsymmetrical";}

        String reverseword="";
        //traversing the word
        for (int i=0;i<word.length();i++)
        {
            char ch=Character.toLowerCase(word.charAt(i));
            int temp=(int)ch;
            temp=temp-97;
            temp=122-temp;//25-temp+97
            reverseword=reverseword+(char)temp;
        }
        //checking for similarity in both words
        for(int i=0;i<word.length();i++)
        {
            if(Character.toLowerCase(word.charAt(i))!=reverseword.charAt(word.length()-i-1))
                {
                    return "unsymmetrical";
                }
        }
        return "symmetrical";
    }
    public static void main(String args[])
    {
        //test case -1
        System.out.println(isSymmetrical("acxz"));
        //test case -2
        System.out.println(isSymmetrical("AcxZ"));
        //test case -1
        System.out.println(isSymmetrical("adxz"));
        //test case -1
         System.out.println(isSymmetrical("acyz"));
    }
}
//time complexity O(n)
//auxillary space O(n)