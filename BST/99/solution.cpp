#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<int> arr;
        int pos = 0;
        getArray(root, arr);
        adjustArray(arr);
        putArray(root, arr, pos);
    }

private:
    void getArray(TreeNode *root, vector<int> &arr) {
        if (!root) { return; }
        getArray(root->left, arr);
        arr.push_back(root->val);
        getArray(root->right, arr);
    }

    void adjustArray(vector<int> &arr) {
        int err_pos1 = -1, err_pos2 = -1;
        for (int prev = 0, i = 1; i < arr.size(); i++, prev++) {
            if (arr[i] < arr[prev]) {
                if (err_pos1 == -1) { err_pos1 = prev; }
                err_pos2 = i;
            }
        }
        if (err_pos1 != -1 && err_pos2 != -1) { swap(arr[err_pos1], arr[err_pos2]); }
    }

    void putArray(TreeNode *root, const vector<int> &arr, int &pos) {
        if (!root) { return; }
        putArray(root->left, arr, pos);
        root->val = arr[pos++];
        putArray(root->right, arr, pos);
    }
};

int main() {
    Solution s;
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(1);
    p->right = new TreeNode(4);
    p->right->left = new TreeNode(2);
    s.recoverTree(p);
}
