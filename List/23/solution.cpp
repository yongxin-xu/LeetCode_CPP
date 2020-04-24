#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *curr = head;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &list : lists) {
            ListNode *lh = list;
            while (lh) {
                pq.push(lh->val);
                lh = lh->next;
            }
        }
        while (!pq.empty()) {
            int val = pq.top();
            pq.pop();
            if (!head) {
                head = new ListNode(val);
                curr = head;
            } else {
                curr->next = new ListNode(val);
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);
    vector<ListNode* > ln_list = {l1,l2,l3};
    Solution s;
    ListNode *ret = s.mergeKLists(ln_list);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    } cout << endl;
}