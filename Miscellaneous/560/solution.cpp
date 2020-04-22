#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums; sums.push_back(0);
        int cnt = 0;
        int temp = 0;
        for (auto &num : nums) {
            temp += num;
            sums.push_back(temp);
        }
        
        for (int i = 0; i < sums.size() - 1; i++) {
            for (int j = i + 1; j < sums.size(); j++) {
                if (sums[j] - sums[i] == k) { cnt++; }
            }
        }

        return cnt;
    }
};

int main() {
    Solution s;
    // vector<int> arr = {1, 2, 3, 1, 2, 2, 1, 3};
    // cout << s.subarraySum(arr, 6) << endl;
    vector<int> arr = {1, 1, 1};
    cout << s.subarraySum(arr, 2) << endl;
    return 0;
}