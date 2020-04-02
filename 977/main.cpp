#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size(), 0);

        // 1. Find the edge of postive numbers and negatives
        //    Split the sorted array into [0 ... edge] and [edge ... A.size()-1]
        int edge = 0;
        for (auto &i : A) {
            if (i < 0) {
                edge++;
                continue;
            }
            break;
        }

        // 2. Transformation => square 
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i] * A[i];
        }

        // 3. Merge [0 ... edge] and [edge ... A.size()-1]
        int idx1 = edge - 1;
        int idx2 = edge;
        int idx = 0;
        while (idx1 >= 0 && idx2 < A.size()) {
            if (A[idx1] <= A[idx2]) {
                ret[idx++] = A[idx1--];
            } else {
                ret[idx++] = A[idx2++];
            }
        }

        while (idx1 >= 0) { ret[idx++] = A[idx1--]; }

        while (idx2 < A.size()) { ret[idx++] = A[idx2++]; }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> test1 = {-4, -1, 0, 3, 10};
    vector<int> ret1 = s.sortedSquares(test1);
    for (auto &r : ret1) { cout << r << " "; } cout << endl;
    vector<int> test2 = {1, 3, 5, 7, 9};
    vector<int> ret2 = s.sortedSquares(test2);
    for (auto &r : ret2) { cout << r << " "; } cout << endl;
    vector<int> test3 = {-9, -7, -5, -3, -1};
    vector<int> ret3 = s.sortedSquares(test3);
    for (auto &r : ret3) { cout << r << " "; } cout << endl;
    vector<int> test4 = {-7, -3, 2, 3, 11};
    vector<int> ret4 = s.sortedSquares(test4);
    for (auto &r : ret4) { cout << r << " "; } cout << endl;

    return 0;
}