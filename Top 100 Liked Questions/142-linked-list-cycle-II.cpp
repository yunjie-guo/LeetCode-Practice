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
    ListNode *detectCycle(ListNode *head) {
         if (head == NULL || head->next == NULL) return NULL;
            /*

            The distance from head to the start of the loop is x1
            The distance from the start of the loop to the point fast and slow meet is x2
            The distance from the point fast and slow meet to the start of the loop is x3
            

            x1 + x2 + x3 + x2 the distance fast pointer walks
            x1 + x2 the distance slow pointer walks
            x1 + x2 + x3 + x2 = 2 (x1 + x2)
            Thus x1 = x3

            */
            ListNode* firstp = head;
            ListNode* secondp = head;
            bool isCycle = false;

            while(firstp != NULL && secondp != NULL) {
                firstp = firstp->next;
                if (secondp->next == NULL) return NULL;
                secondp = secondp->next->next;
                if (firstp == secondp) { isCycle = true; break; }
            }

            if(!isCycle) return NULL;
            firstp = head;
            while( firstp != secondp) {
                firstp = firstp->next;
                secondp = secondp->next;
            }

            return firstp;
    }
};