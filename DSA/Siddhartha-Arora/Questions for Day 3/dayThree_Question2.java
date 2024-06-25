/***Question 2:** Create a function to check if reversing the ASCII values of a string results in the 
same sequence when read backward. If true, return "symmetrical", otherwise return "not 
symmetrical".

##### Inputs:
- A string.
##### Output:
- "symmetrical" if the string meets the criteria, otherwise "not symmetrical".
  
##### Example:

string = "acxz"

##### Output: symmetrical

 */


public class dayThree_Question2{

    public static void main(String[] args) {
        String str = "acxz";
        System.out.println(checkSymmetry(str));
    }
    private static String checkSymmetry(String str) {
        String reverseString = reverseAscii(str);
        String backString = stringReversal(str);
        boolean flag = backString.equals(reverseString);

        return flag ? "symmetrical" : "not symmetrical";
    }
    private static String stringReversal(String str){
        StringBuilder s=new StringBuilder(str);
        s.reverse();
        System.out.println(s.toString());
        return s.toString();
    }
    private static String reverseAscii(String str){
        String res="";
        for(char ch:str.toCharArray()){
            res += (char) ('z' - (ch - 'a'));
        }
        System.out.println(res);

        return res;
    }


}