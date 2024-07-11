import java.util.HashMap;
import java.util.Map;
class Day_4_Question_2
{
    public String isValid(String s){
        HashMap<Character,Integer> map=new HashMap<>();
        String track="";
        
        for(int x=0;x<s.length();x++){
            char ch=s.charAt(x);
            
            if(track.indexOf(ch)!=-1){
                int num=map.get(ch)+1;
                map.put(ch,num);
            }
            else{
                track+=ch;
                map.put(ch,1);
            }
        }
        int max=map.get(track.charAt(0));
        char ch=track.charAt(0);
        boolean equal=true;
        for(Map.Entry<Character,Integer> e: map.entrySet()){
            char c=e.getKey();
            int n=e.getValue();
            if(max<n){
                ch=c;
                max=n;
                equal=false;
            }
            else if(max!=n){
                equal=false;
            }
        }
        
        if(equal==false){
            map.put(ch,--max);
            for(Map.Entry<Character,Integer> e: map.entrySet()){
                if(e.getValue()!=max){
                    return "invalid";
                }
            }
        }
        
        return "valid";
    }
}