#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> climbingLeaderboard(vector<int>& leaderboard, vector<int>& player) {
    vector<int> ranks;
    int n = leaderboard.size();
    int m = player.size();
    vector<int> uniqueLeaderboard = leaderboard;
    sort(uniqueLeaderboard.begin(), uniqueLeaderboard.end(), greater<int>());
    uniqueLeaderboard.erase(unique(uniqueLeaderboard.begin(), uniqueLeaderboard.end()), uniqueLeaderboard.end());
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j < uniqueLeaderboard.size() && player[i] >= uniqueLeaderboard[j]) {
            j++;
        }
        ranks.push_back(j + 1);
    }
    return ranks;
}

int main() {
    int n, m;
    cout << "Enter the number of leaderboard scores: ";
    cin >> n;
    vector<int> leaderboard(n);
    cout << "Enter the leaderboard scores: ";
    for (int i = 0; i < n; i++) {
        cin >> leaderboard[i];
    }
    cout << "Enter the number of player scores: ";
    cin >> m;
    vector<int> player(m);
    cout << "Enter the player scores: ";
    for (int i = 0; i < m; i++) {
        cin >> player[i];
    }
    vector<int> ranks = climbingLeaderboard(leaderboard, player);
    cout << "Ranks: ";
    for (int i = 0; i < ranks.size(); i++) {
        cout << ranks[i] << " ";
    }
}