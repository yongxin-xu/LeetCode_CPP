#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        enum direction {right=0, down, left, up};
        direction dir = right;
        
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        int yLowBound = 0, xLowBound = 0;
        const int M = matrix.size();
        const int N = matrix[0].size();
        int yUpBound = M - 1;    // y => [0, M - 1]
        int xUpBound = N - 1;    // x => [0, N - 1]
        int x = 0, y = 0;
        
        do {
            res.push_back(matrix[y][x]);
            
            // find next (x, y)
            if (dir == right) {
                if (x == xUpBound) {
                    y++;
                    yLowBound++;
                    dir = down;
                } else {
                    x++;
                }
            } else if (dir == down) {
                if (y == yUpBound) {
                    x--;
                    xUpBound--;
                    dir = left;
                } else {
                    y++;
                }
            } else if (dir == up) {
                if (y == yLowBound) {
                    x++;
                    xLowBound++;
                    dir = right;
                } else {
                    y--;
                }
            } else /* (dir == left) */ {
                if (x == xLowBound) {
                    y--;
                    yUpBound--;
                    dir = up;
                } else {
                    x--;
                }            
            }
            
        } while(res.size() != M * N);
        
        return res;
    }
};