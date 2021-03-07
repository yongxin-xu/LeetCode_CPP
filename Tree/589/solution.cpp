/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    
private:
    void helper(Node *root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        
        for (auto &node : root->children) {
            helper(node, res);
        }
    }
};