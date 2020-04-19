#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) { return -1; }
        return binarySearch(nums, target, 0, nums.size()-1);
    }

private:
    int binarySearch(vector<int>& nums, const int target, int low, int high) {
        while (low < high) {
            int current = ((high - low) >> 1) + low;
            if (nums[current] == target) { return current; }
            if (nums[current] > nums[high]) {
                if (nums[low] <= target && target < nums[current]) {
                    high = current - 1;
                } else {
                    low = current + 1;
                }
            } else {
                if (nums[current] < target && target <= nums[high]) {
                    low = current + 1;
                } else {
                    high = current - 1;
                }
            }
        }

        return nums[low] == target ? low : -1;
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution s;
    cout << s.search(nums, 0) << endl;
    cout << s.search(nums, 1) << endl;
    cout << s.search(nums, 2) << endl;
    cout << s.search(nums, 3) << endl;
    cout << s.search(nums, 4) << endl;
    cout << s.search(nums, 5) << endl;
    cout << s.search(nums, 6) << endl;
    cout << s.search(nums, 7) << endl;
    return 0;
}