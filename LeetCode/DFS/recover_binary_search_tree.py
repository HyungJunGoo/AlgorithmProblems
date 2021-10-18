# You are given the root of a binary search tree (BST),
# where the values of exactly two nodes of the tree were swapped by mistake.
# Recover the tree without changing its structure.

from typing import Optional

# [1,3,null,null,2] -> [3,1,null,null,2]


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self) -> None:
        self.first = None
        self.second = None
        self.prev = None

    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.traverse(root)
        self.first.val, self.second.val = self.second.val, self.first.val

    def traverse(self, root: Optional[TreeNode]) -> None:

        if root is None:
            return

        self.traverse(root.left)

        if self.prev is not None:
            if self.first is None and self.prev.val > root.val:
                self.first = self.prev
            if self.first is not None and self.prev.val > root.val:
                self.second = root
        self.prev = root
        self.traverse(root.right)
