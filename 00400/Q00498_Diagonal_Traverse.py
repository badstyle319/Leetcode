import unittest
from typing import List


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        r, c = len(mat), len(mat[0])
        direction, x, y = True, 0, 0
        ret = list()

        while len(ret) < r * c:
            ret.append(mat[x][y])
            if direction:
                if x == 0 or y == c - 1:
                    if y + 1 < c:
                        y += 1
                    else:
                        x += 1
                    direction = not direction
                else:
                    x -= 1
                    y += 1
            else:
                if x == r - 1 or y == 0:
                    if x + 1 < r:
                        x += 1
                    else:
                        y += 1
                    direction = not direction
                else:
                    x += 1
                    y -= 1
        return ret


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().findDiagonalOrder(data)
        self.assertEqual(result, expect)

    def test_case1(self):
        data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        expect = [1, 2, 4, 7, 5, 3, 6, 8, 9]
        self.run_test(data, expect)

    def test_case2(self):
        data = [[1, 2], [3, 4]]
        expect = [1, 2, 3, 4]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
