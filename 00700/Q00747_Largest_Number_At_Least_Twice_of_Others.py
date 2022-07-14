import unittest
from typing import List


class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        maximum = max(nums)
        for num in nums:
            if num != maximum and maximum < 2 * num:
                return -1
        return nums.index(maximum)


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().dominantIndex(data)
        self.assertEqual(result, expect)

    def test_case1(self):
        data = [3, 6, 1, 0]
        expect = 1
        self.run_test(data, expect)

    def test_case2(self):
        data = [1, 2, 3, 4]
        expect = -1
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
