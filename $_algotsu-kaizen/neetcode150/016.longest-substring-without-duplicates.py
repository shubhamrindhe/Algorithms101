class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        r = 0
        result = 0
        f = {}

        while r < len(s):
            c = s[r]
            f[c] = f.get(c, 0) + 1
            while f.get(c, 0) > 1:
                c_ = s[l]
                f[c_] -= 1
                l += 1
            result = max(result, r - l + 1)
            # if f.get(c, 0) == 0:
            #     f[c] = 1
            # elif f[c] == 1:
            #     while l < r and f.get(c, 0) > 0:
            #         c_ = s[l]
            #         f[c_] -= 1
            #         l += 1
            # result = max(result, r - l)
            r += 1
        return result
