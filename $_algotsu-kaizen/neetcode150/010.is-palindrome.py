# 010. Valid Palindrome (https://neetcode.io/problems/is-palindrome?list=neetcode150)

class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
            # print(s[l], s[r])
            if l < r and s[l].lower() == s[r].lower():
                l += 1
                r -= 1
                continue
            # print(s[l], s[r], s[l].lower() == s[r].lower(), l < r)
            return r <= l
        return True
