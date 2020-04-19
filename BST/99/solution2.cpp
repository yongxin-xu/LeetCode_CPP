#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = nullptr;
        inOrderHelper(root, prev);
        if (err_pos1 && err_pos2) {
            swap(err_pos1->val, err_pos2->val);
        }
    }

private:
    void inOrderHelper(TreeNode *root, TreeNode *&prev) {
        if (!root) { return; }
        inOrderHelper(root->left, prev);

        if  (prev && root->val < prev->val) {
            if (!err_pos1) { err_pos1 = prev; }
            err_pos2 = root;
        }
        prev = root;
        inOrderHelper(root->right, prev);
    }
    
private:
    TreeNode *err_pos1 = nullptr, *err_pos2 = nullptr;
};

int main() {
    Solution s;
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(1);
    p->right = new TreeNode(4);
    p->right->left = new TreeNode(2);
    s.recoverTree(p);
}
