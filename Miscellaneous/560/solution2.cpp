#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            cnt += m[sum - k];
            ++m[sum]; 
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 1, 2, 2, 1, 3};
    cout << s.subarraySum(arr, 6) << endl;
    return 0;
}