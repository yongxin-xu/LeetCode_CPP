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
    int diameterOfBinaryTree(TreeNode *root) {
        int ret = 0;
        maxDepth(root, ret);
        return ret;
    }

private:
    int maxDepth(TreeNode *node, int &ret) {
        if (!node) { return 0; }
        int leftSubDepth = maxDepth(node->left, ret);
        int RightSubDepth = maxDepth(node->right, ret);
        ret = max(ret, leftSubDepth+RightSubDepth);
        return max(leftSubDepth, RightSubDepth) + 1;
    }
};

