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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, preorder.size());
    }

private:
    TreeNode *build(vector<int>& preorder, vector<int>& inorder,
                    int startPre, int startIn, int sizeVec) {
        /* endPos should > startPos, if == then this is the end */
        if (sizeVec == 0) return nullptr;
        /* the first element of preorder it the root */
        int rootVal = preorder[startPre];
        int posRoot = 0;
        TreeNode *root = new TreeNode(rootVal);
        /* find rootVal in inorder vector */
        for (int i = startIn; i < startIn + sizeVec; i++) {
            if (inorder[i] == rootVal) posRoot = i;
        }
        
        int sizeLeft = posRoot - startIn;
        int sizeRight = sizeVec - 1 - sizeLeft;
        
        root->left = build(preorder, inorder, startPre+1, startIn, sizeLeft);
        root->right = build(preorder, inorder, startPre+1+sizeLeft, posRoot+1, sizeRight);
        
        return root;
    }
};