#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> calculateRanks(const vector<int>& old_leaderboard, const vector<int>& player_scores) {
    vector<int> leaderboard;
    for (int score : old_leaderboard) {
        if (leaderboard.empty() || leaderboard.back() != score) {
            leaderboard.push_back(score);
        }
    }
    
    vector<int> ranks;
    int n = leaderboard.size();
    
    for (int score : player_scores) {
        //binary search 
        int low = 0, high = n - 1, rank = n + 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (leaderboard[mid] <= score) {
                rank = mid + 1;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        ranks.push_back(rank);
    }
    
    return ranks;
}

int main() {
    vector<int> leaderboard = {100, 90, 90, 80};
    vector<int> player_scores = {70, 80, 105};

    vector<int> player_ranks = calculateRanks(leaderboard, player_scores);

    cout << "Player ranks: ";
    for (int rank : player_ranks) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}