class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), current = 0;
        for (int i = 0; i < n; ++i) {
            if (i > current || current >= n - 1) break;
            current = max(current, i + nums[i]);
        }
        return current >= n - 1;
    }
};