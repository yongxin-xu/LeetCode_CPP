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

typedef struct node {
    TreeNode *tn;
    int colNum;
    int rowNum;
    
    node() = default;
    node(TreeNode *_tn, int _col, int _row): tn(_tn), colNum(_col), rowNum(_row) {}
}node;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // 1. calculate its row number => its level
        // 2. calculate its column number => deduce from its parent 
        // 3. sort them in order => priority queue nlogn, n space complexity
        //    or, we can use a vector to store, and then do a quick sort
        vector<vector<int> > res;
        vector<node *> nodeVector;
        queue<node*> nodeQueue; /* for a level order traversal */
        if (!root) { return res; }
        nodeQueue.push(new node(root, 0, 0));
        
        while (!nodeQueue.empty()) {
            int sz = nodeQueue.size();
            
            for (int i = 0; i < sz; i++) {
                // these nodes are in the same level
                node *ptr = nodeQueue.front();
                nodeQueue.pop();
                nodeVector.push_back(ptr);
                if (ptr->tn->left)  { nodeQueue.push(new node(ptr->tn->left,  ptr->colNum-1, ptr->rowNum+1)); }
                if (ptr->tn->right) { nodeQueue.push(new node(ptr->tn->right, ptr->colNum+1, ptr->rowNum+1)); }
            }
        }
        
        // sort the nodeVector
        sort(nodeVector.begin(), nodeVector.end(), [](const node *a, const node *b) -> bool{
            if (a->colNum < b->colNum) { return true; }
            if (a->colNum > b->colNum) { return false; }
            if (a->rowNum < b->rowNum) { return true; }
            if (a->rowNum > b->rowNum) { return false; }
            return a->tn->val < b->tn->val;
        });
            
        // debug print
        // for (auto &n : nodeVector) {
            // cout << "val: " << n->tn->val << ", col: " << n->colNum << ", row: " << n->rowNum << endl;
        // }
        
        // put vector => res
        int col = 1;
        int cnt = 0;
        while (cnt < nodeVector.size()) {
            vector<int> vtmp;
            node *ptr = nodeVector[cnt];
            int col = ptr->colNum;
            while(col == ptr->colNum) {
                vtmp.push_back(ptr->tn->val);
                if (++cnt >= nodeVector.size()) break;
                ptr = nodeVector[cnt];
            }
            res.push_back(vtmp);
        }
        
        
        return res;        
    }
};