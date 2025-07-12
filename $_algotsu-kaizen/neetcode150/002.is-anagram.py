# 002. Valid Anagram (https://neetcode.io/problems/is-anagram?list=neetcode150)

# import Counter from
from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
