#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum = INT_MIN;
        int indexMax = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxNum) { 
                maxNum = nums[i];
                indexMax = i; 
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == indexMax) continue;
            if ((maxNum * 0.5) < nums[i])
                return -1;
        }
        return indexMax;
    }
};