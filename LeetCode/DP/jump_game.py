from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        can_arrive = len(nums) - 1
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] + i >= can_arrive:
                can_arrive = i

        return can_arrive == 0


s = Solution()
nums = [2, 3, 1, 1, 4]
nums2 = [3, 2, 1, 0, 4]
nums3 = [1, 2, 3]
assert s.canJump(nums3) == True
