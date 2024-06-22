#include <iostream>
#include <vector>

int countValidSegments(const std::vector<int>& chocolate, int birthDay, int birthMonth) {
    int count = 0;
    int n = chocolate.size();
     for (int i = 0; i <= n - birthMonth; ++i) {
        int sum = 0;       
        for (int j = i; j < i + birthMonth; ++j) {
            sum += chocolate[j];
        }
        if (sum == birthDay) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> chocolate = {2, 2, 1, 3, 2};
    int birthDay = 4;
    int birthMonth = 2;
    int ways = countValidSegments(chocolate, birthDay, birthMonth);
    std::cout << "Number of valid ways to divide the chocolate: " << ways << std::endl;

    return 0;
}
