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
        ListNode* p = new ListNode((l1->val + l2->val) % 10);
        ListNode* head = p;
        int C = (l1->val + l2->val) / 10;
        l1 = l1->next; l2 = l2->next;
                       
        while(l1&&l2){
            p->next = new ListNode((l1->val + l2->val + C) % 10);
            C = (l1->val + l2->val + C) / 10;
            p = p->next; l1 = l1->next; l2 = l2->next;
        }
        while(l1){
            p->next = new ListNode((l1->val + C) % 10);
            C = (l1->val + C) / 10;
            p = p->next; l1 = l1->next;
        }
        while(l2){
            p->next = new ListNode((l2->val + C) % 10);
            C = (l2->val + C) / 10;
            p = p->next; l2 = l2->next;
        }
        if(C) p->next = new ListNode(C);
        
        return head;
    }
};
