# Construct Binary Tree from Preorder and Inorder Traversal

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
	def __init__(self):

		self.inorder = None
		self.preorder = None
		self.pn = None
		self.inn = None

	def buildTree(self, preorder, inorder):
		"""
		:type preorder: List[int]
		:type inorder: List[int]
		:rtype: TreeNode
		"""
		self.inorder = inorder
		self.preorder = preorder
		self.pn = dict() #preorder index dict
		self.inn = dict() # inorder index dict
		for i in range(len(preorder)):
			self.pn[preorder[i]] = i
			self.inn[inorder[i]] = i
		r = TreeNode(preorder[0])
		r.left = self.solution(0, self.inn[preorder[0]]-1)
		r.right = self.solution(self.inn[preorder[0]]+1, len(preorder)-1)

		return r


	def solution(self, start, end):
		if start > end:
			return None
		#0, 2
		sub_r_idx = 3001
		for i in range(start, end+1):
			sub_r_idx = min(sub_r_idx, self.pn[self.inorder[i]])
		print(sub_r_idx)
		node = TreeNode(self.preorder[sub_r_idx])
		node_in_idx = self.inn[self.preorder[sub_r_idx]]
		node.left = self.solution(start, node_in_idx-1)
		node.right = self.solution(node_in_idx+1, end)
		return node