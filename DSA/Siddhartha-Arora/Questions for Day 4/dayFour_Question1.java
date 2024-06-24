/*# Questions for Day 4 - (24/06/2024)

## DSA

**Question 1:** Given a string, determine the number of distinct palindromic substrings of a 
specified length.
##### Inputs:
- A string.
- An integer representing the length of the substrings.
##### Output:
- The number of distinct palindromic substrings.
##### Example:
string = "ababa"

length = 3
 */
public class dayFour_Question1 {
    public static void main (String args[]){
        // System.out.println("null");
        String str="ababa";
        int val=3;
        System.out.println(getPalinString(str,val));
    }
    private static int getPalinString(String str,int val){
        //sliding window approach 
        int res=0;
        // int l=0;
        for(int right=0;right<=str.length()-val;right++){
            //r-cal and thsi to string builder and check the rev? if yes the res++ and continue along
            // lets say the st is of 5 then 0-2 1-3 2-4
            String substr = str.substring(right, right + val);
            StringBuilder sb = new StringBuilder(substr);
            if (substr.equals(sb.reverse().toString())) {
                res++;
            }
        }

        return res;
    }
}
