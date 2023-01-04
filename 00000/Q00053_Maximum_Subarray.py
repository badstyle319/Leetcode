import unittest
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        temp = ans = nums[0]

        for num in nums[1:]:
            temp = max(num, temp + num)
            ans = max(ans, temp)

        return ans


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().maxSubArray(data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        expect = 6
        self.run_test(data, expect)

    def test_case2(self):
        data = [1]
        expect = 1
        self.run_test(data, expect)

    def test_case3(self):
        data = [5, 4, -1, 7, 8]
        expect = 23
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
