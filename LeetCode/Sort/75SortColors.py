# 75 <Sort Colors>
"""
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Follow up:
Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
"""

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        r,w,b = 0,0,0 # for count
        for n in nums:
            if n == 0:
                r += 1
            elif n == 1:
                w += 1
            else:
                b += 1
        for i in range(len(nums)):
            if i < r:
                nums[i] = 0
            elif i>=r and i < r+w:
                nums[i] = 1
            else:
                nums[i] = 2
        print(nums)

s = Solution()
# s.sortColors([2,0,2,1,1,0])
s.sortColors([2])