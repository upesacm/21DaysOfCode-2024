#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> climbingLeaderboard(vector<int> leaderboard, vector<int> player_scores) {
    set<int> unique_scores(leaderboard.begin(), leaderboard.end());
    vector<int> sorted_leaderboard(unique_scores.rbegin(), unique_scores.rend());  
    vector<int> result;
    int index = sorted_leaderboard.size() - 1;
    for (int score : player_scores) {
        while (index >= 0 && score >= sorted_leaderboard[index]) {
            index--;
        }
        result.push_back(index + 2);
    }
    return result;
}
int main() {
    vector<int> leaderboard = {100, 90, 90, 80, 75, 60};
    vector<int> player_scores = {50, 65, 77, 90, 102};
    vector<int> result = climbingLeaderboard(leaderboard, player_scores);
    for (int rank : result) {
        cout << rank << " ";
    }
    cout << endl;
    
    return 0;
}
