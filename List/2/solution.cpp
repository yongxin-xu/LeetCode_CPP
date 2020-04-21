#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto *cur1 = l1, *cur2 = l2;
        int plusOne = 0;
        ListNode *cur3 = nullptr, *ret = nullptr;

        for (;cur1 && cur2; cur1=cur1->next, cur2=cur2->next) {
            int digit = cur1->val + cur2->val + plusOne;
            if (digit >= 10) {
                digit -= 10;
                plusOne = true;
            } else {
                plusOne = false;
            }
            if (!cur3) {
                cur3 = new ListNode(digit);
                ret = cur3;
            } else {
                cur3->next = new ListNode(digit);
                cur3 = cur3->next;
            }
        }

        for (;cur1;cur1=cur1->next) {
            int digit = cur1->val + plusOne;
            if (digit >= 10) {
                digit -= 10;
                plusOne = true;
            } else {
                plusOne = false;
            }
            if (!cur3) {
                cur3 = new ListNode(digit);
                ret = cur3;
            } else {
                cur3->next = new ListNode(digit);
                cur3 = cur3->next;
            }
        }

        for (;cur2;cur2=cur2->next)  {
            int digit = cur2->val + plusOne;
            if (digit >= 10) {
                digit -= 10;
                plusOne = true;
            } else {
                plusOne = false;
            }
            if (!cur3) {
                cur3 = new ListNode(digit);
                ret = cur3;
            } else {
                cur3->next = new ListNode(digit);
                cur3 = cur3->next;
            }
        }

        if (plusOne) {
            cur3->next = new ListNode(1);
            cur3 = cur3->next;
        }

        return ret;
    }
};

int main() {
    
}