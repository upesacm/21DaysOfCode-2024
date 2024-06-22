#include <iostream>
#include <vector>
#include <unordered_map>

int countPairsDivisibleByK(const std::vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    std::vector<int> remainderCount(k, 0); 
    remainderCount[0] = 1;   
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        int remainder = sum % k;
        
        if (remainder < 0) {
            remainder += k; 
        }      
        count += remainderCount[remainder];
        remainderCount[remainder]++;
    }    
    return count;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    int result = countPairsDivisibleByK(nums, k);
    std::cout << "Number of valid (i, j) pairs: " << result << std::endl;
    
    return 0;
}
