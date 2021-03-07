import copy

class Solution(object):
    def pathSum(self, root, targetSum):
        self.result = []
        if root == None: return self.result
        current_list = [root.val]
        if sum(current_list) == targetSum and root.left == None and root.right==None:
            self.result.append(current_list)
            return self.result
        self.dfs(root.left, current_list, targetSum)
        current_list = [root.val]
        self.dfs(root.right, current_list, targetSum)
        return self.result

    def dfs(self, root, current_list, targetSum):
        if root == None: return
        current_list.append(root.val)
        if sum(current_list) == targetSum and root.left==None and root.right==None:
            self.result.append(current_list)
        else:
            cp_current_list = copy.deepcopy(current_list)
            self.dfs(root.left, current_list, targetSum)
            current_list = cp_current_list
            self.dfs(root.right, current_list, targetSum)
        return