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
        TreeNode *ptr = root;
        TreeNode *prev = nullptr;

        while (ptr && ptr->val != key) {
            prev = ptr;
            if (key < ptr->val) { ptr = ptr->left; }
            else { ptr = ptr->right; }
        }

        if (!ptr) { return root; }

        if (ptr->left && ptr->right) {
            TreeNode *minPtr = ptr->right;
            TreeNode *minPrev = ptr;
            while(minPtr->left) { 
                minPrev = minPtr;
                minPtr = minPtr->left; 
            }
            ptr->val = minPtr->val;
            ptr = minPtr;
            prev = minPrev;
        }

        TreeNode *sub = nullptr;
        sub = (ptr->left) ? ptr->left : (ptr->right) ?  ptr->right : nullptr;
        
        if (!prev) {
            root = sub;
        } else if (prev->left == ptr) {
            prev->left = sub;
        } else {
            prev->right = sub;
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
