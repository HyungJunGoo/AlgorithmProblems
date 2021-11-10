# https://leetcode.com/problems/balance-a-binary-search-tree/


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def dfs(node: TreeNode):
            if not node:
                return []
            return dfs(node.left) + [node.val] + dfs(node.right)

        list_of_nodes = dfs(root)
        l, r = 0, len(list_of_nodes) - 1

        def make_balanced_BST(l, r) -> TreeNode:
            if l == r:
                return TreeNode(list_of_nodes[l])
            m = (l + r) // 2
            node = TreeNode(list_of_nodes[m])
            if l < m:
                node.left = make_balanced_BST(l, m - 1)
            if m < r:
                node.right = make_balanced_BST(m + 1, r)

        return make_balanced_BST(l, r)
