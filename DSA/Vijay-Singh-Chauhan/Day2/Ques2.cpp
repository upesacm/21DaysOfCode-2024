#include<iostream>
#include<vector>

using namespace std;

vector<int>climbing(vector<int>& leaderboard, vector<int>player_score){
    vector<int>newleaderboard;
    newleaderboard.push_back(leaderboard[0]);
    for(int i=1;i<leaderboard.size();i++){
        if(leaderboard[i]!=leaderboard[i-1]){
            newleaderboard.push_back(leaderboard[i]);
        }
    }

    vector<int>result;
    int j=newleaderboard.size()-1;

    for(int i=0;i<player_score.size();i++){
        while(j>=0 && player_score[i]>=newleaderboard[j]){
            j--;
        }
        result.push_back(j+2);
    }
    return result;

}


int main(){
    int a;
    vector<int>leaderboard;
    vector<int>player_score;

    int lsize,psize;
    cout<<"Enter Size of Leader Board: ";
    cin>>lsize;

    cout<<"Enter LeaderBoard Integer: ";
    for(int i=0;i<lsize;i++){
        cin>>a;
        leaderboard.push_back(a);
    }

    cout<<"Enter Size of player_score: ";
    cin>>psize;

    cout<<"Enter Player_score Integer: ";
    for(int i=0;i<psize;i++){
        cin>>a;
        player_score.push_back(a);
    }

    vector<int>result=climbing(leaderboard,player_score);

    for(int rank : result){
        cout<<rank<< " ";
    }
    return 0;

}
