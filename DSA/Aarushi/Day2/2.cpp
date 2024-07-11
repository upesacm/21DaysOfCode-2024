// Question 2
/*
A player is climbing a leaderboard where scores are ranked in descending order. Given the scores on the leaderboard and the player's scores in the game, determine the player's rank after each new score.
Inputs:

An array of integers representing the leaderboard scores.
An array of integers representing the player's scores. Output:
An array of integers representing the player's rank after each new score.
Example:

leaderboard = [100, 90, 90, 80]

player_scores = [70, 80, 105]

Output: [4, 3, 1]*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> FinalLeaderboard(vector<int> leaderboard, vector<int> player_score){
    set<int, greater<int>> unique_leaderboard(leaderboard.begin(), leaderboard.end());

    vector<int> ranks(unique_leaderboard.begin(), unique_leaderboard.end());

    vector<int> player_ranks;
    int rank_size = ranks.size();
    
    for(int score : player_score) {
        while(rank_size > 0 && score >= ranks[rank_size - 1]) {
            rank_size--;
        }
        player_ranks.push_back(rank_size + 1);
    }
    
    return player_ranks;
}


int main(){
    vector<int> leaderboard = {100, 90, 90, 80};
    vector<int> player_scores = {70, 80, 105};

    vector<int> result = FinalLeaderboard(leaderboard, player_scores);
    for(int rank : result){
        cout <<rank<< " ";
    }
    cout << endl;

    return 0;

}