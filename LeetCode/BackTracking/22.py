# Generate Parentheses
# https://leetcode.com/problems/generate-parentheses/
# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]

class Solution(object):
    result = []
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.result = []
        self.dfs(1,0,1,"(", n)
        return self.result
    
    def dfs(self,l, r, ll, s, n):
        if ll == 2*n:
            if l==r:
                self.result.append(s)
            return
        if l == r:
            self.dfs(l+1, r, ll+1, s+'(', n)
        else:
            self.dfs(l, r+1, ll+1, s+')', n)
            self.dfs(l+1, r, ll+1, s+'(', n)

