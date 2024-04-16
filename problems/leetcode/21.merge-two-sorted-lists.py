# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1, list2):
        if not list2:
            return list1
        if not list1:
            return list2
        
        if list1.val < list2.val:
            mrg_lst = list1
            pointer = list2
        else:
            mrg_lst = list2
            pointer = list1
        
        while mrg_lst and pointer and mrg_lst.next:
            if mrg_lst.next.val > pointer.val:
                tmp = mrg_lst.next
                mrg_lst.next = pointer
                pointer = tmp
            mrg_lst = mrg_lst.next
        
        mrg_lst.next = pointer.val

        return list1 if list1.val < list2.val else list2

