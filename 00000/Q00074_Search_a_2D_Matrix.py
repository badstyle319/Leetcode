import unittest
from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        low, high, mid = 0, len(matrix) - 1, 0

        while low <= high:
            mid = (low + high) // 2
            if target == matrix[mid][0]:
                return True
            elif target < matrix[mid][0]:
                high = mid - 1
            else:
                if target > matrix[mid][len(matrix[0]) - 1]:
                    low = mid + 1
                else:
                    break

        low, high, r = 0, len(matrix[0]) - 1, mid
        if low == high:
            return target == matrix[r][low]
        while low <= high:
            mid = (low + high) // 2
            if target == matrix[r][mid]:
                return True
            elif target < matrix[r][mid]:
                high = mid - 1
            else:
                low = mid + 1

        return False


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().searchMatrix(**data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {'matrix': [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 'target': 3}
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = {'matrix': [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 'target': 13}
        expect = False
        self.run_test(data, expect)

    def test_case3(self):
        data = {'matrix': [[1]], 'target': 1}
        expect = True
        self.run_test(data, expect)

    def test_case4(self):
        data = {'matrix': [[1, 3]], 'target': 3}
        expect = True
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
