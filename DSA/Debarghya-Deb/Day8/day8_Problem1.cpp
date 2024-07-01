#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int maxEqualSum(int N1, int N2, int N3, vector<int>& S1, vector<int>& S2, vector<int>& S3) {
    
    int sum1 = accumulate(S1.begin(), S1.end(), 0);
    int sum2 = accumulate(S2.begin(), S2.end(), 0);
    int sum3 = accumulate(S3.begin(), S3.end(), 0);

    
    int i = 0, j = 0, k = 0;

    while (true) {
        
        if (i == N1 || j == N2 || k == N3) {
            return 0;
        }

        
        if (sum1 == sum2 && sum1 == sum3) {
            return sum1;
        }

        
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= S1[i];
            i++;
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= S2[j];
            j++;
        } else {
            sum3 -= S3[k];
            k++;
        }
    }
}

int main() {
    vector<int> S1 = {4, 2, 3};
    vector<int> S2 = {1, 1, 2, 3};
    vector<int> S3 = {1, 4};
    int N1 = S1.size();
    int N2 = S2.size();
    int N3 = S3.size();
    cout << maxEqualSum(N1, N2, N3, S1, S2, S3) << endl;  

    vector<int> S1_2 = {4, 7};
    vector<int> S2_2 = {10};
    vector<int> S3_2 = {1, 2, 3};
    int N1_2 = S1_2.size();
    int N2_2 = S2_2.size();
    int N3_2 = S3_2.size();
    cout << maxEqualSum(N1_2, N2_2, N3_2, S1_2, S2_2, S3_2) << endl; 

    return 0;
}