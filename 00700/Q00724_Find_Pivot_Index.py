import unittest
from typing import List


class Solution:
    """
    same as question 1991. find the middle index in array
    """
    def pivotIndex(self, nums: List[int]) -> int:
        left = 0
        right = sum(nums)
        for i, num in enumerate(nums):
            right -= num
            if left == right:
                return i
            left += num
        return -1


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().pivotIndex(data)
        self.assertEqual(result, expect)

    def test_case1(self):
        data = [1, 7, 3, 6, 5, 6]
        expect = 3
        self.run_test(data, expect)

    def test_case2(self):
        data = [1, 2, 3]
        expect = -1
        self.run_test(data, expect)

    def test_case3(self):
        data = [2, 1, -1]
        expect = 0
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
