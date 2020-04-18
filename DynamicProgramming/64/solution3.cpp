#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int length = grid.size();
        if (length == 0) { return 0; }
        int width = grid[0].size();
        if (width == 0) { return 0; }
        // opt[i][j] stores the best current sum from (0, 0) to (i, j)
        vector<int> opt(width, INT_MAX);
        opt[0] = 0;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) { 
                    opt[j] += grid[i][j]; 
                } else {
                    opt[j] = grid[i][j] + min(opt[j-1], opt[j]);
                }
            }
        }
        
        return opt[width-1];
    }
};

int main() {
    vector<vector<int>> grid = {
                                {1,3,1},
                                {1,5,1},
                                {4,2,1}
                                };
    Solution s;
    cout << s.minPathSum(grid) << endl;
}