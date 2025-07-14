# 011. Two Integer Sum II (https://neetcode.io/problems/two-integer-sum-ii?list=neetcode150)

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            sigma = numbers[l] + numbers[r]
            if sigma < target:
                l += 1
            elif sigma > target:
                r -= 1
            else:
                return [l + 1, r + 1]
        return [-1, -1]
