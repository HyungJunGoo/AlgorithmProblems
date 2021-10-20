# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.balanced = True

    def height(self, root) -> int:
        if self.balanced == False:
            return 0
        if root is None:
            return 0
        if abs(self.height(root.left) - self.height(root.right)) > 1:
            self.balanced = False
        return max(self.height(root.left), self.height(root.right)) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        if root is not None:
            if abs(self.height(root.left) - self.height(root.right)) > 1:
                self.balanced = False
        return self.balanced
