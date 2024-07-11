#include <iostream>

class Day_1_Question_2 {
public:
    Day_1_Question_2(const int arr[], int size, int k) : arr_(arr), size_(size), k_(k) {}

    int countValidPairs() {
        int count[k_] = {0}; 

        for (int i = 0; i < size_; ++i) {
            int rem = (arr_[i] % k_ + k_) % k_;
            ++count[rem];
        }

        int result = count[0] * (count[0] - 1) / 2; 
        for (int rem = 1; rem <= k_ / 2; ++rem) {
            result += count[rem] * count[k_ - rem];
        }

        
        if (k_ % 2 == 0) {
            result += count[k_ / 2] * (count[k_ / 2] - 1) / 2;
        }

        return result;
    }

private:
    const int* arr_;
    int size_;
    int k_;
};

