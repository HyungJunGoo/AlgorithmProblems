class Solution(object):
    def threeSumClosest(self, nums, target):
        l = len(nums)
        dist = float('inf')
        nums.sort()
        for i in range(l-2):
            lo = i+1
            hi = l-1
            while lo < hi:
                s = nums[i]+nums[lo]+nums[hi]
                if abs(target-s) < abs(dist):
                    dist = target - s
                    if dist == 0:
                        return target
                if s < target:
                    lo += 1
                else:
                    hi -= 1
        return target - dist

if __name__ == "__main__":
    nums = [-1,2,1,-4]
    target = 1
    s = Solution()
    r = s.threeSumClosest(nums, target)
    print(r)