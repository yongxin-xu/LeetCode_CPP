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
    vector<double> averageOfLevels(TreeNode* root) {
        // use a levelorder traversal 
        vector<double> res;
        queue<TreeNode *> nodeQueue;
        TreeNode *ptr = root;
        if (!ptr) return res;
        
        nodeQueue.push(ptr);
        while (!nodeQueue.empty()) {
            auto cnt = nodeQueue.size();
            double sum = 0.0;
            for (auto i = 0; i < cnt; i++) {
                ptr = nodeQueue.front();
                nodeQueue.pop();
                // add to sum
                sum += ptr->val;
                // push its children into queue
                if (ptr->left) nodeQueue.push(ptr->left);
                if (ptr->right) nodeQueue.push(ptr->right);
            }
            res.push_back(sum / cnt);
        }
        return res;
    }
};