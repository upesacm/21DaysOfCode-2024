class Day_4_Question_1
{
    public boolean isPalindrome(String s){
        String str="";
        for(int x=0;x<s.length();x++){
            str=s.charAt(x)+str;
        }
        if(s.equals(str)){
            return true;
        }
        return false;
    }
    public int distinct_palindrome(String s,int length){
        s=s.toLowerCase();
        String track="";
        int count=0;
        for(int x=0;x<=s.length()-length;x++){
            String str=s.substring(x,x+length);
            if(track.indexOf(str)==-1 && isPalindrome(str)){
                count++;
                track+=str+",";
            }
        }
        return count;
    }
}