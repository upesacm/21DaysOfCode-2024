class Day_3_Question_1{
    public String isComplete(String s){
        s=s.toUpperCase();
        for(int x=65;x<=90;x++){
            char ch=(char)x;
            if(s.indexOf(ch)==-1){
                return "incomplete";
            }
        }
        return "complete";
    }
}