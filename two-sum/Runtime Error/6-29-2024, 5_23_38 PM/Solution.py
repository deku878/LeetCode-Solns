// https://leetcode.com/problems/two-sum

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        lo=0
        hi=len(nums)-1
        while lo<=hi:
            if a[lo]+a[hi]==target:
                x=[a[lo],a[hi]]
                lo+=1
                hi-=1
            elif a[lo]+a[hi]<target:
                lo+=1
            else:
                hi-=1
        return x
        