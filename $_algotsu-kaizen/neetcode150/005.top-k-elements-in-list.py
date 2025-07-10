# 005. Top K Frequent Elements (https://neetcode.io/problems/top-k-elements-in-list?list=neetcode150)

from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        carr = Counter(nums)
        # print(carr.items(), sorted(carr.items(), key=lambda kvpair: kvpair[1], reverse=True))
        result = []
        freq_pairs = sorted(carr.items(), key=lambda kvpair: kvpair[1], reverse=True)
        for idx in range(0, k):
            result.append(freq_pairs[idx][0])
        return result
