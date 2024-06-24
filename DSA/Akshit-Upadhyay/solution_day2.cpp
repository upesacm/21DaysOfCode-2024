#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> climbingLeaderboard(vector<int> leaderboard, vector<int> player_scores) {
    vector<int> ranks;
    leaderboard.erase(unique(leaderboard.begin(), leaderboard.end()), leaderboard.end());
    
    int n = leaderboard.size();
    int m = player_scores.size();
    
    int i = n - 1;
    for (int j = 0; j < m; j++) {
        while (i >= 0 && player_scores[j] >= leaderboard[i]) {
            i--;
        }
        ranks.push_back(i + 2);
    }
    
    return ranks;
}

int main() {
    int n, m;
    cout << "Enter the number of scores on the leaderboard: ";
    cin >> n;

    vector<int> leaderboard(n);
    cout << "Enter the scores on the leaderboard: ";
    for (int i = 0; i < n; i++) {
        cin >> leaderboard[i];
    }

    cout << "Enter the number of scores for the player: ";
    cin >> m;

    vector<int> player_scores(m);
    cout << "Enter the player's scores: ";
    for (int i = 0; i < m; i++) {
        cin >> player_scores[i];
    }

    vector<int> result = climbingLeaderboard(leaderboard, player_scores);

    cout << "Player's ranks after each score: ";
    for (int rank : result) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}
