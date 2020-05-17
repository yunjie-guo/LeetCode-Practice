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
        ListNode *pA = headA;
        ListNode *pB = headB;
        if (pA == NULL || pB == NULL) return NULL;
        // get the difference between two distance from the beginning to the end
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
            if (pA == pB) return pA;
            if (pA == NULL) pA = headB;
            if (pB == NULL) pB = headA;
        }
        return pA;
    }
};