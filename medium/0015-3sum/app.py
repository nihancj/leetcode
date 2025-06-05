#!/bin/python

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res =  []
        end = len(nums) - 1
        nums.sort()

        pivot = 0

        for pivot in range(end-1):
            if pivot > 0 and nums[pivot] == nums[pivot-1]:
                print("skip: ", pivot)
                continue
            p1 = pivot+1
            p2 = end
            while (p1<p2):
                pnum = nums[pivot]
                twosum = nums[p1] + nums[p2]

                if (twosum == -pnum):
                    res.append([pnum, nums[p1], nums[p2]])

                if twosum > -pnum:
                    t = nums[p2]
                    while nums[p2] == t:
                        p2 -= 1
                        if p2 <= p1:
                            break
                else:
                    t = nums[p1]
                    while nums[p1] == t:
                        p1 += 1
                        if p2 <= p1:
                            break


        return res



nums = [0,0, 0]
solution = Solution()
print(solution.threeSum(nums))
