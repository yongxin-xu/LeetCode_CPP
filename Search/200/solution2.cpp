#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int length = grid.size(), width = grid[0].size(), cnt = 0;
        
        vector<int> dirX{-1, 0, 1, 0}, dirY{0, 1, 0, -1};
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] != '1') { continue; }
                ++cnt;
                queue<int> q;
                q.push(i);
                q.push(j);
                while (!q.empty()) {
                    int x = q.front(); q.pop();
                    int y = q.front(); q.pop();
                    if (x + 1 < length && grid[x + 1][y] == '1') {
                        grid[x + 1][y] = 'v';
                        q.push(x + 1);
                        q.push(y);
                    }
                    if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                        grid[x - 1][y] = 'v';
                        q.push(x - 1);
                        q.push(y);
                    }
                    if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                        grid[x][y - 1] = 'v';
                        q.push(x);
                        q.push(y - 1);
                    }
                    if (y + 1 < width && grid[x][y + 1] == '1') {
                        grid[x][y + 1] = 'v';
                        q.push(x);
                        q.push(y + 1);
                    }
                }
            }
        }
        return cnt;
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