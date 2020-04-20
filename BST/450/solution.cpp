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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) { return nullptr; }
        if (root->val == key) {
            TreeNode* new_root;
            if (root->left && root->right) {
                new_root = root->right;
                while (new_root->left) {
                    new_root = new_root->left;
                }
                new_root->left = root->left;
                new_root = root->right;
            } else if (root->left) {
                new_root = root->left;
            } else if (root->right) {
                new_root = root->right;
            }
            delete root;
            return new_root;
        }       
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

int main() {
    Solution s;
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(1);
    p->right = new TreeNode(4);
    p->right->left = new TreeNode(2);
    s.deleteNode(p, 4);
}
