//Yash Gupta 500125397
//Assuming duplicate in leaderboard shares same rank
public class Day_2_Q2 {
    public static int[] RankAfterEachRound(int leaderboard[],int player_score[])
    {
        if(leaderboard==null || player_score ==null){return null;} //checking if either of the array is null
        int rank[]=new int[player_score.length];

        for(int i=0;i<player_score.length;i++)
        {
            int count=0;
            int j=0;
            while(j<leaderboard.length&& player_score[i]<leaderboard[j])//using insertion sort approach
            {
                if(j<leaderboard.length-1 &&leaderboard[j]==leaderboard[j+1]){j++;continue;}//checking for duplicates
                count++;
                j++;
            }
            rank[i]=count+1;
        }
        return rank;
    }
    public static void main(String[] args) {
       int leaderboard []= {120,100,90,85,85,85,80,75};//test case-1
       int player_score[]={70, 85, 90, 105, 130};
       int rank[]=RankAfterEachRound(leaderboard, player_score);
       System.out.println("Output from test case-1");
       for(int i=0;i<rank.length;i++)
       {
        System.out.println(rank[i]);
       }

       int leaderboard1[]={100, 90, 90, 80};//test case-2 
       int player_scores1[]= {70, 80, 105};
       int rank1[]=RankAfterEachRound(leaderboard1, player_scores1);
       System.out.println("Output from test case-2");
       for(int i=0;i<rank1.length;i++)
       {
        System.out.println(rank1[i]);
       }


    }

}