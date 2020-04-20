#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) { return nullptr; }
        TreeNode *root = new TreeNode(preorder.front());
        for (int i = 1; i < preorder.size(); i++) {
            bstInsert(root, preorder[i]);
        }
        return root;
    }

    void bstInsert(TreeNode *root, int val) {
        if (val < root->val) {
            if (root->left) {
                bstInsert(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        } else {
            if (root->right) {
                bstInsert(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
    }
};

int main() {

}