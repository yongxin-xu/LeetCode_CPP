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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++)
            indexMap[inorder[i]] = i;
        return build(inorder, postorder, indexMap, 0, 0, inorder.size());
    }
    
private:
    TreeNode *build(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &indexMap,
                    int startIn, int startPost, int sizeVec) {
        TreeNode *root = nullptr;
        if (sizeVec == 0) return nullptr;
        
        int rootVal = postorder[startPost+sizeVec-1];
        root = new TreeNode(rootVal);
        int rootPos = indexMap[rootVal];
        int sizeLeft = rootPos - startIn;
        int sizeRight = sizeVec - sizeLeft - 1;
        
        root->left = build(inorder, postorder, indexMap, startIn, startPost, sizeLeft);
        root->right = build(inorder, postorder, indexMap, rootPos+1, startPost+sizeLeft, sizeRight);
        
        return root;
    }
};