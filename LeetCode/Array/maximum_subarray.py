# Given an integer array nums, find the contiguous subarray (containing at least one number)
# which has the largest sum and return its sum.

# A subarray is a contiguous part of an array.

# dp[i] => max_subarray[0~i]
# dp[i] = a[i] + (dp[i-1] if dp[i-1] > 0 else 0)


def get_maximum_subarr(nums: list[int]) -> int:

    dp = [0 for _ in range(len(nums))]
    dp[0] = nums[0]
    max_sum = dp[0]
    for i in range(1, len(nums)):
        dp[i] = nums[i] + (dp[i - 1] if dp[i - 1] > 0 else 0)
        max_sum = max(max_sum, dp[i])
    return max_sum


if __name__ == "__main__":
    num = get_maximum_subarr([-2, 1, -3, 4, -1, 2, 1, -5, 4])
    print(num)

    num = get_maximum_subarr([-1])
