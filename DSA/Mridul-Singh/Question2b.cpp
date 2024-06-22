#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ranking(vector<int> leaderboard, vector<int> player_scores)
{   // Remove duplicates and sort in descending order
    sort(leaderboard.begin(), leaderboard.end(), greater<int>());
    leaderboard.erase(unique(leaderboard.begin(), leaderboard.end()), leaderboard.end());
    vector<int> newRanks;
    int n = leaderboard.size();
    int i = n - 1;
    for (int score : player_scores)
    {
        while (i >= 0 && score >= leaderboard[i])
        {
            i--;
        }
        newRanks.push_back(i + 2);
    }
    return newRanks;
}

int main()
{
    vector<int> leaderboard = {100, 90, 90, 80};
    vector<int> player_scores = {70, 80, 105};
    auto it = ranking(leaderboard, player_scores);
    cout <<"[";
    for (int rank : it)
    {
        cout << rank << " ";
    }
    cout <<"]";
    return 0;
}
