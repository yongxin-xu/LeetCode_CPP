/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // if d == 1 => d is root
        if (d == 1) {
            TreeNode *newRoot = new TreeNode(v, root, nullptr);
            return newRoot;
        }
        
        // otherwise, we do a levelorder traversal
        /* root == nullptr is impossible here */
        queue<TreeNode *> nodeQueue; 
        nodeQueue.push(root);
        
        for (int i = 2; i < d; i++) {
            /* this is at the ith level */
            int sz = nodeQueue.size();
            for (int j = 0; j < sz; j++) {
                auto ptr = nodeQueue.front();
                nodeQueue.pop();
                if (ptr->left)  { nodeQueue.push(ptr->left);  }
                if (ptr->right) { nodeQueue.push(ptr->right); }
            }
        }
        
        /* insert new level */
        while(!nodeQueue.empty()) {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            auto tempLeft = node->left;
            auto tempRight = node->right;
            node->left = new TreeNode(v);
            node->right = new TreeNode(v);
            node->left->left = tempLeft;
            node->right->right = tempRight;
        }
        
        return root;
    }
};