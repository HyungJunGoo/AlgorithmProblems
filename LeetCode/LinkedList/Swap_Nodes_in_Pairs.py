from collections import copy as cp

class ListNode(object):
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        new_head = None
        last_visit_node=None
        while head!=None:
            next = head.next 
            if next == None:
                break
            if new_head == None:
                new_head = next
            head.next = next.next
            next.next = head
            if last_visit_node != None:
                last_visit_node.next = next

            last_visit_node = head
            head = head.next
            
        return new_head