/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /* level order traversal ? */
        queue<Node *> levelQueue;
        Node *ptr = root;
        
        if (!root) { return root; }
        levelQueue.push(ptr);
        
        do {
            auto sz = levelQueue.size();
            Node *prev = nullptr;
            for (auto i = 0; i < sz; i++) {
                if (i == 0) prev = levelQueue.front(); 
                ptr = levelQueue.front();
                levelQueue.pop();
                if (ptr->left) levelQueue.push(ptr->left);
                if (ptr->right) levelQueue.push(ptr->right); 
                if (i == 0) continue;
                prev->next = ptr;   
                prev = ptr;
            }
        } while(!levelQueue.empty());
        
        return root;
    }
};