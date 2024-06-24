//here is the solution to second DSA Question , DAY 2
#include <iostream>
#include <vector>

using namespace std;

vector<int> climbing_leaderboard(const vector<int>& leaderboard, const vector<int>& player_scores) {
  vector<int> ranks;
  for (int score : player_scores) {
    ranks.push_back(upper_bound(leaderboard.begin(), leaderboard.end(), score) - leaderboard.begin() + 1);
  }
  return ranks;
}

int main() {
  vector<int> ranks = climbing_leaderboard(leaderboard, player_scores);
  for (int rank : ranks) cout << rank << " ";
  cout << endl;
  return 0;
}
