# Binary Tree Level Order Traversal

# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        if root == None:
        	return result

        result.append([root.val])

        q = deque()
        q.append([root.left, 1])
        q.append([root.right, 1])
        
        tmp = []
        current_num = 1
        while q:
        	node, num = q.popleft()
        	if node == None:
        		continue
        	if num !=current_num:
        		result.append(tmp)
        		tmp = []
        		current_num+=1
        	
        	tmp.append(node.val)
        	q.append([node.left, num+1])
        	q.append([node.right, num+1])
        if len(tmp) != 0:
            result.append(tmp)

        return result