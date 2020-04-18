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
        int opt[length][width];
        opt[0][0] = grid[0][0];

        for (int i = 1; i < length; i++) { opt[i][0] = opt[i-1][0] + grid[i][0]; }
        for (int j = 1; j < width; j++) { opt[0][j] = opt[0][j-1] + grid[0][j]; }

        for (int i = 1; i < length; i++) {
            for (int j = 1; j < width; j++) {
                opt[i][j] = grid[i][j] + min(opt[i-1][j], opt[i][j-1]);
            }
        }
        
        return opt[length-1][width-1];
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