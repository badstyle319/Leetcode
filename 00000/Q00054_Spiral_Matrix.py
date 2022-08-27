import unittest
from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        import operator

        m, n = len(matrix), len(matrix[0])
        pos, idx = (0, -1), 0
        direction = ((0, 1), (1, 0), (0, -1), (-1, 0))
        visited = set((i, j) for i in range(m) for j in range(n))
        ret = []

        while len(visited) > 0:
            target = tuple(map(operator.add, pos, direction[idx]))
            if target in visited:
                pos = target
                ret.append(matrix[target[0]][target[1]])
                visited.remove(target)
            else:
                idx = (idx + 1) % 4

        return ret


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().spiralOrder(data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        expect = [1, 2, 3, 6, 9, 8, 7, 4, 5]
        self.run_test(data, expect)

    def test_case2(self):
        data = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
        expect = [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
