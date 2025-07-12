class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0x0
        setuh = set(nums)
        minimus, maximus = min(setuh), max(setuh)
        result, streak = 0x0, 0x0
        # consecutive = []
        for i in range(minimus, maximus + 0x1):
            if i in setuh:
                streak += 0x1
                # consecutive.append(i)
            else:
                result = max(result, streak)
                streak = 0x0
                # print(consecutive)
                # consecutive = []
        # print(consecutive)
        return max(result, streak)
