#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int length = grid.size();
        if (length == 0) { return 0; }
        int width = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1') {
                    helper(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

private:
    void helper(vector<vector<char>> &grid, int i, int j) {
        if (grid[i][j] == '1') {
            grid[i][j] = 'v';  // visited
        } else {
            return;
        }
        if (i > 0) {
            helper(grid, i - 1, j);
        }
        if (i < grid.size() - 1) {
            helper(grid, i + 1, j);
        }
        if (j > 0) {
            helper(grid, i, j - 1);
        }
        if (j < grid[0].size() - 1) {
            helper(grid, i, j + 1);
        }
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};
    cout << s.numIslands(grid) << endl;
    vector<vector<char>> grid2 = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << s.numIslands(grid2) << endl;
    return 0;
}