/*
Question 2: A player is climbing a leaderboard where scores are ranked in descending order.
Given the scores on the leaderboard and the player's scores in the game, determine the player's rank after each new score.

Inputs:
An array of integers representing the leaderboard scores.
An array of integers representing the player's scores.

Output:
An array of integers representing the player's rank after each new score.

Example:
leaderboard = [100, 90, 90, 80]
player_scores = [70, 80, 105]

Output: [4, 3, 1]
*/

// Since the array given is sorted we need to find the search for the position, binary search will work effective.
// We have to modify the algorithm a little bit. It is equivalent to LeetCode question: Search Insert Position
// There can be another approach i.e. just concatenate and sort and find the index but this won't work incase of duplicates, so to handle that we need to remove duplicates and find out the position.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int currentRank(vector<int>& leaderboard_scores, int player_currentscore)
    {
        int left = 0;
        int right = leaderboard_scores.size() - 1;
        int middle = 0;

        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (leaderboard_scores[middle] == player_currentscore)
                return middle + 1;
            else if (leaderboard_scores[middle] > player_currentscore)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return left + 1;
    }
};

int main()
{
    cout << "Enter the size of leaderboard scores: -" << endl;
    int leaderboardsize;
    cin >> leaderboardsize;

    cout << "Enter the leaderboard scores: -" << endl;
    vector<int> leaderboard_scores(leaderboardsize);
    for (int i = 0; i < leaderboardsize; i++)
    {
        cout << "Enter the " << i + 1 << " position: ";
        cin >> leaderboard_scores[i];
    }

    cout << "Enter the size of player scores: -" << endl;
    int player_scores_size;
    cin >> player_scores_size;

    cout << "Enter the player scores: -" << endl;
    vector<int> player_scores(player_scores_size);
    for (int i = 0; i < player_scores_size; i++)
    {
        cout << "Enter the " << i + 1 << " score: ";
        cin >> player_scores[i];
    }

    Solution ans;

    vector<int> playerrank(player_scores_size);
    for (int i = 0; i < player_scores_size; i++)
    {
        playerrank[i] = ans.currentRank(leaderboard_scores, player_scores[i]);
    }

    cout << "Player rank in leaderboard after each score is: ";
    for (int i = 0; i < player_scores_size; i++)
    {
        cout << playerrank[i] << " ";
    }
    cout << endl;

    return 0;
}
