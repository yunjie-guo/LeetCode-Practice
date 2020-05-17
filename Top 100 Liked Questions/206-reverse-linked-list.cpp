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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        // use the recursion
        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
};


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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* temp = nullptr;
        ListNode* first = head;
        ListNode* second = head->next;
        while (second){
            // inverse the pointer one by one
            first->next = temp;
            temp = first;
            first = second;
            second = second->next;
        }
        first->next = temp;
        return first;
    }
};