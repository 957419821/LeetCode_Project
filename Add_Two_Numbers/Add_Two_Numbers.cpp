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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode((l1->val + l2->val) % 10);
        ListNode* resultHead = result;
        int C = (l1->val + l2->val) / 10;
        l1 = l1->next; l2 = l2->next;
                       
        while(l1 != NULL && l2 != NULL){
            result->next = new ListNode((l1->val + l2->val + C) % 10);
            C = (l1->val + l2->val + C) / 10;
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            result->next = new ListNode((l1->val + C) % 10);
            result = result->next;
            C = (l1->val + C) / 10;
            l1 = l1->next;
        }
        while(l2 != NULL){
            result->next = new ListNode((l2->val + C) % 10);
            result = result->next;
            C = (l2->val + C) / 10;
            l2 = l2->next;
        }
        if(C != 0) result->next = new ListNode(C);
        
        return resultHead;
    }
};
