# https://leetcode.com/problems/balance-a-binary-search-tree/


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def depth(self, root: TreeNode):
        if not root:
            return 0
        return max(self.depth(root.left), self.depth(root.right)) + 1

    def move_right(self, root: TreeNode, parent=None, isLeft=False, isRIght=False):
        new_root = root.left
        root.left.right, root.left = root, root.left.right
        if parent:
            if isLeft:
                parent.left = root.left
            if isRIght:
                parent.right = root.left
        return new_root

    def move_left(self, root: TreeNode, parent=None, isLeft=False, isRIght=False):
        new_root = root.right
        root.right.left, root.right = root, root.right.left
        if parent:
            if isLeft:
                parent.left = root.right
            if isRIght:
                parent.right = root.right
        return new_root

    def recursion(self, root: TreeNode, parent=None, isLeft=False, isRight=False):
        if root.left is not None:
            self.recursion(root.left, root, isLeft=True)
        if root.right is not None:
            self.recursion(root.right, root, isRight=True)
        l_depth = self.depth(root.left)
        r_depth = self.depth(root.right)
        while abs(l_depth - r_depth) >= 2:
            print(f"{root.left.val} | {root.right.val}")
            print(f"{l_depth} | {r_depth}")
            if l_depth > r_depth:
                root = self.move_right(root, parent, isLeft, isRight)
                l_depth, r_depth = self.depth(root.left), self.depth(root.right)
            else:
                root = self.move_left(root, parent, isLeft, isRight)
                l_depth, r_depth = self.depth(root.left), self.depth(root.right)
        return root

    def balanceBST(self, root: TreeNode) -> TreeNode:
        return self.recursion(root)
