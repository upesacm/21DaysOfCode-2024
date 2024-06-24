class Day_3_Question_2{
    public String isSymmetric(String s){
        s=s.toUpperCase();
        String sym="",rev="";
        int len=s.length();
        for(int x=0;x<len;x++){
            char ch=s.charAt(x);
            sym+= (char)(90- (int)ch +65);
            rev=ch+rev;
        }
        if(sym.equals(rev)){
            return "symmetrical";
        }
        return "not symmetrical";
    }
}