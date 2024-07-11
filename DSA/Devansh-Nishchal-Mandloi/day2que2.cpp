//A simple solution with time complexity of O(n*m) where n is the size of the leaderboard vector and m is the size of playerScores vector

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<int> findRank(vector<int> leaderboard, vector<int> playerScores) {
        vector<int> result(playerScores.size());
        // Remove duplicates and sort leaderboard in descending order
        leaderboard.erase(unique(leaderboard.begin(), leaderboard.end()), leaderboard.end());
        sort(leaderboard.rbegin(), leaderboard.rend());

        for (int i = 0; i < playerScores.size(); i++) {
            int rank = 1;
            bool found = false;
            for (int j = 0; j < leaderboard.size(); j++) {
                if (playerScores[i] >= leaderboard[j]) {
                    result[i] = rank;
                    found = true;
                    break;
                }
                rank++;
            }
            if (!found) {
                result[i] = rank;
            }
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the size of the leaderboard" << endl;
    cin >> n;
    vector<int> leaderboard(n);

    cout << "Enter the leaderboard scores" << endl;
    for (int i = 0; i < n; i++) {
        cin >> leaderboard[i];
    }

    int m;
    cout << "Enter the number of player scores" << endl;
    cin >> m;
    vector<int> playerScores(m);

    cout << "Enter the scores of the player" << endl;
    for (int i = 0; i < m; i++) {
        cin >> playerScores[i];
    }

    Solution s;
    vector<int> result = s.findRank(leaderboard, playerScores);

    cout << "The rank of the player corresponding to his/her scores is: ";
    for (int rank : result) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}
