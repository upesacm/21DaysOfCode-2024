#include <iostream>

class Day_1_Question_1 {
public:
    static void validSegments(const int candy[], int day, int month) {
        int leftIndex = 0;
        int rightIndex = month - 1;
        int segCount = 0;

        
        int candySize = 0;
        while (candy[candySize] != -1)
            ++candySize;

        while (rightIndex < candySize) {
            int sum = 0;
            for (int i = leftIndex; i <= rightIndex; ++i)
                sum += candy[i];

            if (sum == day)
                ++segCount;

            ++leftIndex;
            ++rightIndex;
        }

        std::cout << "Valid segments count: " << segCount << std::endl;
    }
};

