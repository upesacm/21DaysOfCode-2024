#include <iostream>
using namespace std;

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) return n;

    int temp[n];
    int j = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[n - 1];

    for (int i = 0; i < j; ++i) {
        arr[i] = temp[i];
    }

    return j;
}

int* climbingLeaderboard(int leaderboard[], int lb_size, int player_scores[], int ps_size) {
    sortDescending(leaderboard, lb_size);
    int unique_count = removeDuplicates(leaderboard, lb_size);
    int* ranks = new int[ps_size];

    for (int i = 0; i < ps_size; ++i) {
        int score = player_scores[i];

        // Binary search for the correct position
        int low = 0, high = unique_count;

        while (low < high) {
            int mid = (low + high) / 2;
            if (leaderboard[mid] > score) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        ranks[i] = low + 1;
    }

    return ranks;
}

int main() {
    int leaderboard[100], lb_size, player_scores[100], ps_size;
    cout << "Enter the number of scores in the leaderboard: ";
    cin >> lb_size;
    cout << "Enter the scores in the leaderboard: ";
    for (int i = 0; i < lb_size; i++) {
        cin >> leaderboard[i];
    }

    cout << "Enter the number of scores of the player: ";
    cin >> ps_size;
    cout << "Enter the scores of the player: ";
    for (int i = 0; i < ps_size; i++) {
        cin >> player_scores[i];
    }

    int* ranks = climbingLeaderboard(leaderboard, lb_size, player_scores, ps_size);

    for (int i = 0; i < ps_size; ++i) {
        cout << ranks[i] << " ";
    }
    cout << endl;
}
