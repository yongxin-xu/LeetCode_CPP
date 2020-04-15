#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret;
        helper(root, k, ret);
        return ret;
    }

private:
    void helper(TreeNode *cur, int &k, int &ret) {
        if (!cur) { return; }
        helper(cur->left, k, ret);
        k--;
        if (k == 0) {
            ret = cur->val;
            return;
        }
        helper(cur->right, k, ret);
    }
};