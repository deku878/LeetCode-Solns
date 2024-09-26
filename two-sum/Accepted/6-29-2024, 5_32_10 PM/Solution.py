// https://leetcode.com/problems/two-sum

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
      num={}
      n=len(nums)
      for i in range(n):
        co=target-nums[i]
        if co in num:
            return [num[co],i]
        num[nums[i]]=i
      return []

        