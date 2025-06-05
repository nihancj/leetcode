from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        currSum = 0

        for n in nums:
            currSum = max([0, currSum])

            currSum += n

            if currSum > maxSum:
                maxSum = currSum

        return maxSum
