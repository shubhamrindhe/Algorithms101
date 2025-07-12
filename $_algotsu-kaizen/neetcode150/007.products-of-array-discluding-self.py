from functools import reduce

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # print(reduce)
        # PI = reduce(lambda acc, e: acc * e, nums)
        # return [(0 if e == 0 else int(PI / e)) for e in nums]
        prefix = []
        suffix = []
        acc = 1
        for e in nums:
            acc = acc * e
            prefix.append(acc)
        acc = 1
        for e in reversed(nums):
            acc = acc * e
            suffix.insert(0, acc)
        # print(prefix, suffix)
        return [
            (prefix[i - 1] if i > 0 else 1)
            *
            (suffix[i + 1] if i < len(nums) - 1 else 1)
            for i, n in enumerate(nums)
        ]
