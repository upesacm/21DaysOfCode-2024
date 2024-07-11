class Day_2_Question_2
{
    public int[] leaderboard_rank(int[] leaderboard,int player_scores[]){
        int p_len=player_scores.length,l_len=leaderboard.length;
        int ranks[]=new int[p_len];
        
        for(int x=0;x<p_len;x++){
            int rank=1;
            for(int y=0;y<l_len;y++){
                if(player_scores[x]>=leaderboard[y]){
                    break;
                }
                else if(y+1!=l_len && leaderboard[y]==leaderboard[y+1]){
                    continue;
                }
                rank++;
            }
            ranks[x]=rank;
        }
        return ranks;
    }
}