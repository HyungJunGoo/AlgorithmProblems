class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:

        result = []
        add_one = 0
        while l1 is not None or l2 is not None:
            _new_node = ListNode(
                (l1.val if l1 is not None else 0)
                + (l2.val if l2 is not None else 0)
                + add_one
            )
            add_one = 0
            if _new_node.val >= 10:
                add_one += 1
                _new_node.val %= 10
            result.append(_new_node)
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next
        if add_one == 1:
            result.append(ListNode(1))
        l3 = result[0]

        for i in range(len(result) - 1):
            result[i].next = result[i + 1]
        return l3
