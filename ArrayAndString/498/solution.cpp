#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        /* 2 directions right-up = 0, left-down = 1*/
        int direction = 0;
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        const int M = matrix.size();
        const int N = matrix[0].size();
        int cx = 0, cy = 0;
        int cnt = 0;
        do {
            res.push_back(matrix[cy][cx]);
            cnt++;
            if (direction == 0) {
                // go right-up
                if (outOfBound(cy-1, cx+1, M, N)) {
                    if (cx + 1 < N)
                        cx += 1;
                    else if (cy + 1 < M)
                        cy += 1;
                    direction = 1;
                } else {
                    cy -= 1;
                    cx += 1;
                }
            } else {
                if (outOfBound(cy+1, cx-1, M, N)) {
                    if (cy + 1 < M)
                        cy += 1;
                    else if (cx + 1 < N)
                        cx += 1;
                    direction = 0;
                } else {
                    cy += 1;
                    cx -= 1;
                }
            }
        }while(cnt != M * N);
        return res;
    }
    
private:
    bool outOfBound(int cy, int cx, const int M, const int N) {
        return (cy < 0) || (cy >= M) || (cx < 0) || (cx >= N);
    }
};