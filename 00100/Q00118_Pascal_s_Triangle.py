import unittest
from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        rv = [[1]]
        for i in range(1, numRows):
            rv.append([1])
            if i > 1:
                rv[i].extend([rv[i - 1][j] + rv[i - 1][j + 1] for j in range(len(rv[i - 1]) - 1)])
            rv[i].append(1)
        return rv


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().generate(data)
        self.assertEqual(result, expect)

    def test_case1(self):
        data = 5
        expect = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
        self.run_test(data, expect)

    def test_case2(self):
        data = 1
        expect = [[1]]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
