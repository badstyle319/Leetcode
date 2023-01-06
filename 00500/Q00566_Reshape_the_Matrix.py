import unittest
from typing import List


class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])

        if m * n != r * c:
            return mat

        ret, temp = [], []
        for arr in mat:
            for num in arr:
                temp.append(num)
                if len(temp) == c:
                    ret.append(temp.copy())
                    temp.clear()
        return ret


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().matrixReshape(**data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {'mat': [[1, 2], [3, 4]], 'r': 1, 'c': 4}
        expect = [[1, 2, 3, 4]]
        self.run_test(data, expect)

    def test_case2(self):
        data = {'mat': [[1, 2], [3, 4]], 'r': 2, 'c': 4}
        expect = [[1, 2], [3, 4]]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
