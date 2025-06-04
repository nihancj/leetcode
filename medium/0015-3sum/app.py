#!/bin/python

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]] = [[]]
        n = 0
        i = 0
        k = len(nums) - 1
        nums.sort()

        while(k-i > 1):
            diff = nums[i] + nums[k]
            diff_is_neg = diff < 0
            if diff_is_neg:
                itters = range(i+1, k, 1)
            else:
                itters = range(k-1, i, -1)

            for j in itters:
                sum = diff + nums[j]
                if diff_is_neg and sum > 0:
                    break
                if not diff_is_neg and sum < 0:
                    break
                if sum == 0:
                    if result[n] == [nums[i], nums[j], nums[k]]:
                        continue;
                    n += 1
                    result.append([nums[i], nums[j], nums[k]])

            # if i+1 - i < k - k-1:
            if diff_is_neg:
                i += 1
            else:
                k -= 1

        del result[0]
        return result



nums = [-1,0,1,2,-1,-4]
solution = Solution()
print(solution.threeSum(nums))
