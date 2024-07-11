#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> leaderboard;
    vector<int> scores;

    int leaderboard_players;
    cout << "The no. of players on the leaderboard are: ";
    cin >> leaderboard_players;

    for (int i = 0; i < leaderboard_players; i++) {
        int leaderboard_scores;
        cout << "Leaderboard Score: ";
        cin >> leaderboard_scores;
        leaderboard.push_back(leaderboard_scores);
    }

    int playing_time;
    cout << "Times the player played: ";
    cin >> playing_time;

    for (int i = 0; i < playing_time; i++) {
        int player_scores;
        cout << "Player Score: ";
        cin >> player_scores;
        scores.push_back(player_scores);
    }

    // Create a sorted unique leaderboard
    set<int, greater<int>> s(leaderboard.begin(), leaderboard.end());
    vector<int> sorted_leaderboard(s.begin(), s.end());

    vector<int> final_positions;

    for (int i = 0; i < playing_time; i++) {
        auto it = lower_bound(sorted_leaderboard.begin(), sorted_leaderboard.end(), scores[i], greater<int>());
        int rank = distance(sorted_leaderboard.begin(), it) + 1;
        final_positions.push_back(rank);
    }

    for (int i = 0; i < final_positions.size(); i++) {
        cout << final_positions[i] << endl;
    }

    return 0;
}
