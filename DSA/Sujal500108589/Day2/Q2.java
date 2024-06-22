import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Set;

public class Q2 {
    public static void rank(int []leaderBoard,int []playerScores){
        ArrayList<Integer> ans=new ArrayList<>();
        for(int i=0;i<playerScores.length;i++){
            int low=0,high=leaderBoard.length-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(playerScores[i]>=leaderBoard[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            ans.add(low+1);
        }
        System.out.println("Ranks:");
        for(int ele:ans){
            System.out.print(ele+" ");
        }
    }
    public static void main(String[] args) {
        int leaderBoard[]={100, 90, 90, 80};
        int playerScores[]={70, 80, 105};
        Set<Integer> uniqueSet = new LinkedHashSet<>();
        for (int num : leaderBoard) {
            uniqueSet.add(num);
        }
        int[] uniqueArray = uniqueSet.stream().mapToInt(Integer::intValue).toArray();
        Arrays.toString(uniqueArray);
        rank(uniqueArray,playerScores);
    }
}
