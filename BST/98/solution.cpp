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
    bool isValidBST(TreeNode *root) {
        TreeNode *prev = nullptr;
        return inorderHelper(root, prev);
    }

private:
    // The result of inorder traversal of a BST is a sorted array.
    bool inorderHelper(TreeNode *root, TreeNode *&prev) {
        if (!root) { return true; }
        bool res = inorderHelper(root->left, prev);
        if (!res) { return false; }
        if (prev && root->val <= prev->val) { return false; }
        prev = root;
        return inorderHelper(root->right, prev);
    }
};

int main() {
    Solution s;
    // Example 1. nullptr
    TreeNode *p1 = nullptr;
    cout << "p1: " << s.isValidBST(p1) << endl;

    // Example 2. True
    TreeNode *p2 = new TreeNode(8);
    p2->left = new TreeNode(7);
    p2->left->left = new TreeNode(5);
    p2->left->left->right = new TreeNode(6);
    p2->right = new TreeNode(12);
    p2->right->left = new TreeNode(10);
    p2->right->left->left = new TreeNode(9);
    p2->right->left->right = new TreeNode(11);
    p2->right->right = new TreeNode(14);
    p2->right->right->left = new TreeNode(13);
    cout << "p2: " << s.isValidBST(p2) << endl;

    // Example 3. False
    TreeNode *p3 = new TreeNode(8);
    p3->left = new TreeNode(7);
    p3->left->left = new TreeNode(5);
    p3->left->left->right = new TreeNode(6);
    p3->right = new TreeNode(13);
    p3->right->left = new TreeNode(10);
    p3->right->left->left = new TreeNode(9);
    p3->right->left->right = new TreeNode(11);
    p3->right->right = new TreeNode(14);
    p3->right->right->left = new TreeNode(13);
    cout << "p3: " << s.isValidBST(p3) << endl;

    // Example 4. False
    TreeNode *p4 = new TreeNode(8);
    p4->left = new TreeNode(7);
    p4->left->left = new TreeNode(5);
    p4->left->left->right = new TreeNode(6);
    p4->right = new TreeNode(12);
    p4->right->left = new TreeNode(10);
    p4->right->left->left = new TreeNode(9);
    p4->right->left->right = new TreeNode(10);
    p4->right->right = new TreeNode(14);
    p4->right->right->left = new TreeNode(13);
    cout << "p4: " << s.isValidBST(p4) << endl;

    // Example 5. False
    TreeNode *p5 = new TreeNode(1);
    p5->left = new TreeNode(1);
    cout << "p5: " << s.isValidBST(p5) << endl;

    return 0;
}