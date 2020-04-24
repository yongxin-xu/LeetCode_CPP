#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) { return nullptr; }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { break; }
        }
        if (!fast->next || !fast->next->next) {
            return nullptr;
        }
        
        ListNode *ptr1 = fast, *ptr2 = head;
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};

int main() {
    Solution s;
    ListNode *ln = new ListNode(3);
    ln->next = new ListNode(2);
    ln->next->next = new ListNode(0);
    ln->next->next->next = new ListNode(4);
    ln->next->next->next->next = ln->next;
    auto l2 = s.detectCycle(ln);
    cout << l2->val << endl;
    return 0;
}