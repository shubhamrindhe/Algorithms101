# 006. Encode and Decode Strings (https://neetcode.io/problems/string-encode-and-decode?list=neetcode150)

from enum import Enum

class ParseState(Enum):
    META = "_"
    ADD = "+"

class Solution:

    def encode(self, strs: List[str]) -> str:
        result = ""
        for s in strs:
            result += f"[{len(s)}]{s}"
        return result

    def decode(self, s: str) -> List[str]:
        print(s)
        result = []
        state = ParseState.META
        meta = ""
        length = 0
        for c in s:
            if state == ParseState.META:
                if c == '[':
                    state = ParseState.META
                    meta = ""
                elif c == "]":
                    length = int(meta)
                    result.append("")
                    state = ParseState.META if length == 0 else ParseState.ADD
                else:
                    meta += c
            elif state == ParseState.ADD:
                result[-1] += c
                if length == len(result[-1]):
                    state = ParseState.META
        return result
