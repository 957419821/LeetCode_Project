# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        C = (l1.val + l2.val) // 10
        result = l = ListNode((l1.val + l2.val) % 10)
        l1 = l1.next; l2 = l2.next
        while l1 or l2 or C:
            s = (l1 and [l1.val] or [0])[0] + (l2 and [l2.val] or [0])[0] + C
            l.next = ListNode(s % 10)
            C = s // 10
            l = l.next; l1 = (l1 and [l1.next] or [None])[0]; l2 = (l2 and [l2.next] or [None])[0]
        return result
         
