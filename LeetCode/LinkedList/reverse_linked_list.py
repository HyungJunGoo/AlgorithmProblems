# https://leetcode.com/problems/reverse-linked-list-ii/
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:

        if left == right:
            return head
        i = 1
        prev_node_of_left = []
        mid_nodes = []
        next_node_of_right = []
        while 1:
            if i < left:
                prev_node_of_left.append(head)
            elif i >= left and i <= right:
                mid_nodes.append(head)
            else:
                next_node_of_right.append(head)
            i += 1
            head = head.next
            if not head:
                break
        mid_nodes = mid_nodes[::-1]
        nodes = prev_node_of_left + mid_nodes + next_node_of_right
        for idx in range(1, len(nodes)):
            nodes[idx - 1].next = nodes[idx]
            if idx == len(nodes) - 1:
                nodes[idx].next = None
        return nodes[0]
