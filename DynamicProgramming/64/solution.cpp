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
        int steps_left = width + length - 2;
        int min_sum = INT32_MAX;
        bfsHelper(grid, 0, 0, length-1, width-1, 0, min_sum, steps_left);
        return min_sum;
    }

private:
    void bfsHelper(vector<vector<int>>& grid, int cur_row, int cur_col,
                   const int end_row, const int end_col, int cur_sum,
                   int &min_sum, int steps_left) {
        cur_sum += grid[cur_row][cur_col];
        steps_left--;
        if (cur_sum >= min_sum) { return; }
        if (cur_row == end_row && cur_col == end_col) {
            if (cur_sum < min_sum) { min_sum = cur_sum;}
            return ;
        }
        if (cur_row < end_row && cur_sum + grid[cur_row+1][cur_col] + steps_left - 1 < min_sum) {
            bfsHelper(grid, cur_row+1, cur_col, end_row, end_col, cur_sum, min_sum, steps_left);
        }
        if (cur_col < end_col && cur_sum + grid[cur_row][cur_col+1] + steps_left - 1 < min_sum) {
            bfsHelper(grid, cur_row, cur_col+1, end_row, end_col, cur_sum, min_sum, steps_left);
        }
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