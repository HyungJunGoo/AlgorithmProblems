# https://leetcode.com/problems/valid-sudoku/

from collections import defaultdict

class Solution():
    def __init__(self) -> None:
        # y, x
        self.pointset = {
            1 : (0,0),
            2 : (0,3),
            3 : (0,6),
            4 : (3,0),
            5 : (3,3),
            6 : (3,6),
            7 : (6,0),
            8 : (6,3),
            9 : (6,6),
        }

    def check_row(self,board, i):
        ht = defaultdict(lambda: False)
        for n in range(9):
            if board[i][n] == '.':
                continue
            if ht[board[i][n]] == False:
                ht[board[i][n]] = True
            else:
                return False
        return True
    
    def check_col(self,board, i):
        ht = defaultdict(lambda: False)
        for n in range(9):
            if board[n][i] == '.':
                continue
            if ht[board[n][i]] == False:
                ht[board[n][i]] = True
            else:
                return False
        return True
    
    def check_box(self, board, i):
        y, x = self.pointset[i]
        ht = defaultdict(lambda: False)
        for r in range(3):
            for c in range(3):
                if board[y+r][x+c] == '.':
                    continue
                if ht[board[y+r][x+c]] == False:
                    ht[board[y+r][x+c]] = True
                else:
                    return False
        return True


    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for row in range(9):
            if self.check_row(board,row) == False:
                return False
        for col in range(9):
            if self.check_col(board, col) == False:
                return False
        for box in range(9):
            if self.check_box(board, box) == False:
                return False
        return True
            