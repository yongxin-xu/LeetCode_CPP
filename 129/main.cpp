#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, int &sum, int cur) {
        if (!root) { return; }
        
        cur = cur * 10 + root->val;
        if (!root->left && !root->right) {
            sum += cur;
            return;
        }

        dfs(root->left, sum, cur);
        dfs(root->right, sum, cur);
    }

    int sumNumbers(TreeNode* root) {
        sum = 0;
        if (root == nullptr) { return 0; }
        dfs(root, sum, 0);
        return sum;
    }

private:
    int sum;
};

int main() {
    Solution s;
    TreeNode *t = new TreeNode(0);
    t->left = new TreeNode(1);
    cout << s.sumNumbers(t) << endl;
}