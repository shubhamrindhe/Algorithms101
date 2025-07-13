# 008. Valid Sudoku (https://neetcode.io/problems/valid-sudoku?list=neetcode150)

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        setuh = set()
        for r, row in enumerate(board):
            for c, data in enumerate(row):
                if data == ".":
                    continue
                rhash = f"r{r}{data}"
                chash = f"c{c}{data}"
                bhash = f"b{(r // 0x3) * 0x3 + (c // 0x3)}{data}"
                if rhash in setuh or chash in setuh or bhash in setuh:
                    return False
                setuh.add(rhash)
                setuh.add(chash)
                setuh.add(bhash)
            # print(row)
        return True
