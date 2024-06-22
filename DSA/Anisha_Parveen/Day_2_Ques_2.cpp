#include <bits/stdc++.h>
using namespace std;

void rankOfPlayers(vector<int> leaderBoard, vector<int> playerScores)
{
    set<int, greater<int>> scores;
    for (int i = 0; i < leaderBoard.size(); i++)
    {
        scores.insert(leaderBoard[i]);
    }

    vector<int> finalRanks;
    for (int i = 0; i < playerScores.size(); i++)
    {
        scores.insert(playerScores[i]);

        auto it = scores.find(playerScores[i]);
        int rank = distance(scores.begin(), it) + 1;

        finalRanks.push_back(rank);
    }
    
    for (int i = 0; i < playerScores.size(); i++)
    {
        cout << finalRanks[i] << " ";
    }
}

int main()
{
    vector<int> leaderBoard = {100, 90, 90, 80};
    vector<int> playerScores = {70, 80, 105};

    rankOfPlayers(leaderBoard, playerScores);

    return 0;
}
