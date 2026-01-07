class Solution:
    def trap(self, heights: List[int]) -> int:
        left = [0] * len(heights)
        right = [0] * len(heights)

        maximus = 0
        for i, h in enumerate(heights):
            left[i] = maximus
            maximus = max(maximus, h)

        maximus = 0
        for i in range(len(heights) - 1, -1, -1):
            right[i] = maximus
            maximus = max(maximus, heights[i])

        # print(left)
        # print(right)
        result = 0

        for i, h in enumerate(heights):
            bound = min(left[i], right[i])
            if bound > heights[i]:
                result += bound - heights[i]

        return result
