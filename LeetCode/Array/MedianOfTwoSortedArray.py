from copy import copy
from bisect import bisect_left as bl
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        result = float()
        arr = copy(nums1)
        for n in nums2:
            i = bl(arr, n)
            arr = arr[:i] + [n] + arr[i:]
        l = len(arr)
        print(arr)
        if l % 2 == 0:            
            result += (arr[(l//2)-1]+arr[l//2])/2
        else:
            result += float(arr[l//2])
        return result

if __name__ == "__main__":
    solution = Solution()
    print(solution.findMedianSortedArrays(nums1=[1,2], nums2=[3,4]))