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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) { return new TreeNode(val); }
        helper(root, val);
        return root;
    }

private:
    void helper(TreeNode *cur, int val) {
        if (val < cur->val) {
            if (cur->left) {
                helper(cur->left, val);
            } else {
                cur->left = new TreeNode(val);
            }
        } else /* (val > root->val) */ {
            if (cur->right) {
                helper(cur->right, val);
            } else {
                cur->right = new TreeNode(val);
            }
        }
    }
};

int main() {
    Solution s;
    TreeNode *p1 = new TreeNode(4);
    p1->left = new TreeNode(2);
    p1->left->left = new TreeNode(1);
    p1->left->right = new TreeNode(3);
    p1->right = new TreeNode(7);
    s.insertIntoBST(p1, 5);
}