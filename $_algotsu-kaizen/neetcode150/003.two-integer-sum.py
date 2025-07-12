# 003. Two Sum (https://neetcode.io/problems/two-integer-sum?list=neetcode150)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapuh = {}
        for idx, n in enumerate(nums):
            counter_part = target - n
            if counter_part in mapuh:
                return [mapuh[counter_part], idx]
            mapuh[n] = idx
        return [-1, -1]
