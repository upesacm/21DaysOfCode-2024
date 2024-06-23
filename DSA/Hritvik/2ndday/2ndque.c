#include<stdio.h>
int main(){
    int nleader,nplayer,i,j;
    printf("Enter nleader ");
    scanf("%d",&nleader);
    int leaderboard[nleader];

    for(i=0;i<nleader;i++){
        printf("Enter number ");
        scanf("%d",&leaderboard[i]);
    }

    printf("Enter nplayer ");
    scanf("%d",&nplayer);
    int players[nplayer];

    for(i=0;i<nplayer;i++){
        printf("Enter number ");
        scanf("%d",&players[i]);
    }

    int newleader[nleader],count=0,value;
    for(i=0;i<nleader;i++){
        if(leaderboard[i]!=-1){
            value=leaderboard[i];
            for(j=i+1;j<nleader;j++){
                if(leaderboard[i]==leaderboard[j]){
                    leaderboard[j]=-1;
                }
            }
            leaderboard[i]=-1;
            newleader[count]=value;
            count++;
        }
    }

    int player=1,flag=0;
    for(i=0;i<nplayer;i++){
        flag=0;
        for(j=0;j<count;j++){
            if(players[i]>=newleader[j]){
                printf("player%d = %d\n",player,j+1);
                player++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("player%d = %d\n",player,count+1);
            player++;
        }
    }
    return 0;
}
