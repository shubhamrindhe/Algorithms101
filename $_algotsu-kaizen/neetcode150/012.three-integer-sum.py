# 012. 3Sum (https://neetcode.io/problems/three-integer-sum?list=neetcode150)

from collections import defaultdict
from collections import Counter

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        # ncnt = defaultdict(int)
        # pcnt = defaultdict(int)
        # for n in nums:
        #     if n < 0:
        #         ncnt[n] = ncnt[n] + 1
        #     else:
        #         pcnt[n] = pcnt[n] + 1
        """
        f = Counter(nums)
        setuh = set()
        result = []
        for i, I in enumerate(nums):
            f[I] -= 1
            JK = -I
            for j in range(i + 1, len(nums)):
                J = nums[j]
                K = JK - J
                if J in f:
                    f[J] -= 1
                if f[K] > 0:
                    if f"{I}.{J}.{K}" in setuh or f"{I}.{K}.{J}" in setuh:
                        continue
                    result.append([I, J, K])
                    setuh.add(f"{I}.{J}.{K}")
                    setuh.add(f"{I}.{K}.{J}")
                if J in f:
                    f[J] += 1
        """
        result = []
        i = 0x0
        # for i, I in enumerate(nums):
        while i < len(nums):
            I = nums[i]
            JK = -I
            j, k = i + 0x1, len(nums) - 0x1
            while j < k:
                J, K = nums[j], nums[k]
                shift_left, shift_right = False, False
                if J + K < JK:
                    shift_left = True
                elif J + K > JK:
                    shift_right = True
                else:
                    result.append([I, J, K])
                    shift_left, shift_right = True, True
                while shift_left and j < len(nums) and J == nums[j]:
                    j += 0x1
                while shift_right and k >= 0x0 and K == nums[k]:
                    k -= 0x1
            while i < len(nums) and I == nums[i]:
                    i += 0x1
        return result
