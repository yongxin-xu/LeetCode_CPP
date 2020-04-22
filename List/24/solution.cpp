#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto slow = head;
        ListNode *fast = nullptr, *prev = nullptr;
        if (slow && slow->next) { fast = slow->next; }

        while (slow && fast) {
            slow->next = fast->next;
            fast->next = slow;
            if (prev) {
                prev->next = fast;
            } else {
                head = fast;
            }
            prev = slow;
            slow = slow->next;
            if (slow) { fast = slow->next; }
        }

        return head;
    }
};

int main() {
    Solution s;
    ListNode *ln = new ListNode(1);
    ln->next = new ListNode(2);
    ln->next->next = new ListNode(3);
    ln->next->next->next = new ListNode(4);
    auto l2 = s.swapPairs(ln);
    return 0;
}