class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maximus = 0
        result = 0
        for i in range(len(prices) - 1, -1, -1):
            if maximus > prices[i]:
                kai = maximus - prices[i]
                result = max(kai, result)
            maximus = max(maximus, prices[i])
        return result
