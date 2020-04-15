#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto len = nums.size();
        vector<int> before(len, 1), after(len, 1), output(len, 1);
        for (auto i = 0; i < nums.size()-1; i++) {
            before[i+1] = before[i] * nums[i];
            after[nums.size()-i-2] = after[nums.size()-i-1] * nums[nums.size()-i-1];
        }
        for (auto i = 0; i < nums.size(); i++) {
            output[i] = before[i] * after[i];
        }
        return output;
    }
};

int main() {
    Solution s;
    vector<int> input = {1, 2, 3, 4};
    vector<int> output = s.productExceptSelf(input);
    for (auto &v : output) { cout << v << " "; } cout << endl;
}