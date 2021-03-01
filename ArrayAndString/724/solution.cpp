#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        int pivotValue = 0;
        for (auto &num : nums)
            rightSum += num;
        for (int i = 0; i < nums.size(); i++) {
            leftSum += pivotValue;
            pivotValue = nums[i];
            rightSum -= pivotValue;
            if (leftSum == rightSum) return i;
        }
        return -1;
    }
};