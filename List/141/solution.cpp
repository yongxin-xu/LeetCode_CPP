#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) { return false; }
        ListNode *slow = head, *fast = head->next;
        while (fast) {
            if (fast == slow) { return true; }
            if (!fast->next || !fast->next->next) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};

int main() {
    Solution s;
    ListNode *ln = new ListNode(1);
    ln->next = new ListNode(2);
    ln->next->next = new ListNode(3);
    ln->next->next->next = new ListNode(4);
    auto l2 = s.hasCycle(ln);
    return 0;
}