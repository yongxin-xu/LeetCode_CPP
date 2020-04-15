#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto len = nums.size();
        vector<int> output(len, 1);
        for (int i = 0; i < nums.size()-1; i++) {
            output[i+1] = output[i] * nums[i];
        }
        int temp = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            output[i] *= temp;
            temp *= nums[i];
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