#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        vector<int> result;
        if (!root) { return result; }
        int currentNum = 0, currentCnt = 0, maxCnt = -1;
        helper(result, root, currentNum, currentCnt, maxCnt);
        if (currentCnt == maxCnt) {
            result.push_back(currentNum);
        } else if (currentCnt > maxCnt) {
            result.clear();
            result.push_back(currentNum);
            maxCnt = currentCnt;
        } else { /* do nothing */ }
        return result;
    }

private:
    void helper(vector<int> &vec, TreeNode *root, int &currentNum, 
                int &currentCnt, int &maxCnt) {
        if (!root) { return; }
        helper(vec, root->left, currentNum, currentCnt, maxCnt);
        if (maxCnt != -1 && root->val == currentNum) {
            currentCnt++;
        } else {
            if (currentCnt == maxCnt) {
                vec.push_back(currentNum);
            } else if (currentCnt > maxCnt) {
                vec.clear();
                vec.push_back(currentNum);
                maxCnt = currentCnt;
            } else { /* do nothing */ }
            currentCnt = 1;
            currentNum = root->val;
        }
        helper(vec, root->right, currentNum, currentCnt, maxCnt);
    }
};

int main() {
    Solution s;
    TreeNode *p1 = new TreeNode(8);
    p1->left = new TreeNode(7);
    p1->left->left = new TreeNode(5);
    p1->left->left->right = new TreeNode(6);
    p1->right = new TreeNode(12);
    p1->right->left = new TreeNode(10);
    p1->right->left->left = new TreeNode(9);
    p1->right->left->right = new TreeNode(11);
    p1->right->right = new TreeNode(14);
    p1->right->right->left = new TreeNode(13);
    vector ret1 = s.findMode(p1);
    for (auto &r : ret1) { cout << r << " "; } cout << endl;
    return 0;
}