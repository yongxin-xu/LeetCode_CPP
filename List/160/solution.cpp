/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        ListNode *intersect = nullptr;
        int lenA = 0;
        int lenB = 0;
        
        while (ptrA != nullptr) { ptrA = ptrA->next; lenA++; }
        while (ptrB != nullptr) { ptrB = ptrB->next; lenB++; }
        
        ptrA = headA;
        ptrB = headB;
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while(diff-- > 0) { ptrA = ptrA->next; }
        } else if (lenA < lenB) {
            int diff = - lenA + lenB;
            while(diff-- > 0) { ptrB = ptrB->next; }
        }
        
        // cout << ptrA->val << " " << ptrB->val;
        
        while(ptrA && ptrB) {
            if (ptrA == ptrB) { intersect = ptrA; break; }
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        } 
        
        return intersect;
    }
};