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
        ListNode preHead(0), *p = &preHead;
        int C = 0;
        while(l1 || l2 || C){
            int sum = (l1? l1->val: 0) + (l2? l2->val: 0) + C;
            C = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next; l1 = l1->next; l2 = l2->next;
        }
        return preHead.next;
    }
};
