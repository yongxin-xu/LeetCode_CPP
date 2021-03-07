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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        queue<Node *> nodeQueue;
        
        if (!root) { return res; }
        nodeQueue.push(root);
        
        while(!nodeQueue.empty()) {
            /* 1. record how many nodes are there in this level */
            int sz = nodeQueue.size();
            vector<int> vec;
            
            for (int i = 0; i < sz; i++) {
                /* 2. get the front of the queue, and pop that out */
                Node *ptr = nodeQueue.front();
                nodeQueue.pop();
                /* 3. visit the ptr we just get */   
                vec.push_back(ptr->val);
                for (auto &node : ptr->children)
                    nodeQueue.push(node);
            }
            res.push_back(vec);
        }
        
        return res;
    }
};