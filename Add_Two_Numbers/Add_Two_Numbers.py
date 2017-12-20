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
        while l1 != None and l2 != None:
            l.next = ListNode((l1.val + l2.val + C) % 10)
            C = (l1.val + l2.val + C) // 10
            l = l.next; l1 = l1.next; l2 = l2.next
        while l1 != None:
            l.next = ListNode((l1.val + C) % 10)
            C = (l1.val + C) // 10
            l = l.next; l1 = l1.next
        while l2 != None:
            l.next = ListNode((l2.val + C) % 10)
            C = (l2.val + C) // 10
            l = l.next; l2 = l2.next
        if C != 0:
            l.next = ListNode(C)
        return result
            
