import unittest
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            buf = [ch for ch in row if ch != '.']
            if len(set(buf)) != len(buf):
                return False

        for col in zip(*board):
            buf = [ch for ch in col if ch != '.']
            if len(set(buf)) != len(buf):
                return False

        for x in (0, 3, 6):
            for y in (0, 3, 6):
                buf = [board[x + i][y + j] for i in range(3) for j in range(3) if board[x + i][y + j] != '.']
                if len(set(buf)) != len(buf):
                    return False

        return True

    def isValidSudoku_prime(self, board: List[List[str]]) -> bool:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]
        prod = 1
        for p in primes:
            prod *= p
        boxes = [prod] * 9
        rows = [prod] * 9
        cols = [prod] * 9
        for r in range(9):
            for c in range(9):
                s = board[r][c]
                if s == ".":
                    continue
                b = (r // 3) * 3 + c // 3
                p = primes[int(s) - 1]
                if boxes[b] % p != 0:
                    return False
                boxes[b] /= p
                if rows[r] % p != 0:
                    return False
                rows[r] /= p
                if cols[c] % p != 0:
                    return False
                cols[c] /= p
        return True


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().isValidSudoku_prime(data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
                ["6", ".", ".", "1", "9", "5", ".", ".", "."],
                [".", "9", "8", ".", ".", ".", ".", "6", "."],
                ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
                ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
                ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                [".", "6", ".", ".", ".", ".", "2", "8", "."],
                [".", ".", ".", "4", "1", "9", ".", ".", "5"],
                [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = [["8", "3", ".", ".", "7", ".", ".", ".", "."],
                ["6", ".", ".", "1", "9", "5", ".", ".", "."],
                [".", "9", "8", ".", ".", ".", ".", "6", "."],
                ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
                ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
                ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                [".", "6", ".", ".", ".", ".", "2", "8", "."],
                [".", ".", ".", "4", "1", "9", ".", ".", "5"],
                [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
        expect = False
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
