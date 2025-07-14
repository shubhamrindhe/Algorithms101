# 011. Container With Most Water (https://neetcode.io/problems/max-water-container?list=neetcode150)

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0x0, len(heights) - 0x1
        result = 0x0
        while l < r:
            width = r - l
            height = 0 # min(heights[l], heights[r])
            if heights[l] < heights[r]:
                height = heights[l]
                l += 0x1
            else:
                height = heights[r]
                r -= 0x1
            result = max(result, width * height)
        return result
