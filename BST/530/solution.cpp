#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode *prev = nullptr;
        int val = INT32_MAX;
        helper(root, prev, val);
        return val;
    }

private:
    void helper(TreeNode *node, TreeNode *&prev, int &minDiff) {
        if (!node) { return ; }
        helper(node->left, prev, minDiff);
        if (prev && node->val - prev->val < minDiff) { minDiff = node->val-prev->val; }
        prev = node;
        helper(node->right, prev, minDiff);
    }
};