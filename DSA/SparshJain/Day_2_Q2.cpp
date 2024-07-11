#include <iostream>
using namespace std;

int removeDuplicates(int leaderboard[], int n, int uniqueLeaderboard[]) {
    if (n == 0) return 0;
    uniqueLeaderboard[0] = leaderboard[0];
    int index = 1;
    for (int i = 1; i < n; i++) {
        if (leaderboard[i] != leaderboard[i - 1]) {
            uniqueLeaderboard[index] = leaderboard[i];
            index++;
        }
    }
    return index;
}


int findRank(int leaderboard[], int n, int score) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (leaderboard[mid] == score) {
            return mid + 1; 
        } else if (leaderboard[mid] < score) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low + 1;  
}

int main() {
    
    cout << "Enter the number of scores in the leaderboard: ";
    int leaderboardno;
    cin >> leaderboardno;

    int leaderboardarray[leaderboardno];
    cout << "Enter " << leaderboardno << " leaderboard scores: ";
    for (int i = 0; i < leaderboardno; i++) {
        cin >> leaderboardarray[i];
    }

   
    cout << "Enter the number of player scores to find ranks for: ";
    int nofoplayers;
    cin >> nofoplayers;

    int playerscores[nofoplayers];
    cout << "Enter " << nofoplayers << " player scores: ";
    for (int i = 0; i < nofoplayers; i++) {
        cin >> playerscores[i];
    }

   
    int unique_leaderboard[leaderboardno];
    int unique_leaderboard_size = removeDuplicates(leaderboardarray, leaderboardno, unique_leaderboard);

    
    int player_ranks[nofoplayers];
    for (int i = 0; i < nofoplayers; i++) {
        player_ranks[i] = findRank(unique_leaderboard, unique_leaderboard_size, playerscores[i]);
    }

   
    cout << "Player ranks: [";
    for (int i = 0; i < nofoplayers; i++) {
        cout << player_ranks[i];
        cout<<",";
        
    }
    cout << "]" << endl;

    return 0;
}
