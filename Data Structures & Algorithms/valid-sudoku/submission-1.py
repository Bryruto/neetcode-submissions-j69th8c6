class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)
        column = defaultdict(set)
        box = defaultdict(set)

        length = 9

        for r in range(length):
            for c in range(length):
                if board[r][c] == ".":
                    continue
                elif (board[r][c] in rows[r] or 
                        board[r][c] in column[c] or
                        board[r][c] in box[(r//3,c//3)]):
                        return False

                rows[r].add(board[r][c])
                column[c].add(board[r][c])
                box[(r // 3,c // 3)].add(board[r][c])
        return True 
                    


        