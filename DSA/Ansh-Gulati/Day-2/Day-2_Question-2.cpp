#include <iostream>
#include <vector>
using namespace std;

vector<int> playerRank(int sizeOfLeaderboardArray, int sizeOfPlayerArray, int leaderboard_scores[], int player_scores[])
{
    vector<int> rank(sizeOfPlayerArray);
    vector<int> unique_leaderboard;

    // Remove duplicates from leaderboard scores
    unique_leaderboard.push_back(leaderboard_scores[0]);
    for (int i = 1; i < sizeOfLeaderboardArray; ++i)
    {
        if (leaderboard_scores[i] != leaderboard_scores[i - 1])
        {
            unique_leaderboard.push_back(leaderboard_scores[i]);
        }
    }

    int n = unique_leaderboard.size();
    int index = n - 1; // last index

    // Calculating rank for each player score
    for (int i = 0; i < sizeOfPlayerArray; ++i)
    {
        int player_score = player_scores[i];

        while (index >= 0 && player_score >= unique_leaderboard[index])
        {
            index--;
        }

        // The player's rank is index + 2
        rank[i] = index + 2;
    }

    return rank;
}

int main()
{
    int sizeOfLeaderboardArray;
    cout << "Enter the size of leaderboard array: ";
    cin >> sizeOfLeaderboardArray;

    int leaderboard_scores[100];
    cout << "Input the scores in the leaderboard: ";
    for (int i = 0; i < sizeOfLeaderboardArray; ++i)
    {
        cin >> leaderboard_scores[i];
    }

    int sizeOfPlayerArray;
    cout << "Enter the size of player array: ";
    cin >> sizeOfPlayerArray;

    int player_scores[100];
    cout << "Input the scores of the player: ";
    for (int i = 0; i < sizeOfPlayerArray; ++i)
    {
        cin >> player_scores[i];
    }

    vector<int> rank = playerRank(sizeOfLeaderboardArray, sizeOfPlayerArray, leaderboard_scores, player_scores);

    cout << "The player's rank after each new score is: ";
    for (int i = 0; i < sizeOfPlayerArray; ++i)
    {
        cout << rank[i] << " ";
    }
    cout << endl;

    return 0;
}
