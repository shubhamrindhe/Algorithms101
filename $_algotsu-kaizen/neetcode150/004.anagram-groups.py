# 004. Group Anagrams (https://neetcode.io/problems/anagram-groups?list=neetcode150)

from collections import Counter

# class DisjointSets:
#     __init__(self, ):

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        carr = [Counter(s) for s in strs]
        processed = [False for s in strs]
        # print(carr, processed)

        result = []
        for idx, fd in enumerate(carr):
            if processed[idx]:
                continue
            anagrams = [strs[idx]]
            for i in range(idx + 1, len(strs)):
                if fd == carr[i]:
                    anagrams.append(strs[i])
                    processed[i] = True
            result.append(anagrams)
        return result
