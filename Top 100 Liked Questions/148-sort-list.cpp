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
   ListNode* findCenter(ListNode* head)
    {
        // two pointers
        if(!head || !head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        
        ListNode* center = slow->next;
        slow->next = NULL;
        return center;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        // merge two linked lists
        ListNode temp(0);
        ListNode* ptr = &temp;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        
        if(l1) ptr->next = l1;
        else ptr->next = l2;
        
        return temp.next;
    }
    
    ListNode* sortHelper(ListNode* head)
    {
        if(!head || !head->next) return head;
        
        // separate in the center
        ListNode* center = findCenter(head);
        
        ListNode* l = sortHelper(head);
        ListNode* r = sortHelper(center);
        
        return merge(l, r);
    }

    ListNode* sortList(ListNode* head) 
    {
        // merge sort
        return sortHelper(head);
    }
};