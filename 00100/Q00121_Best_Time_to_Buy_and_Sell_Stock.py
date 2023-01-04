import unittest
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, temp = 0, 0
        for i in range(1, len(prices)):
            temp += prices[i] - prices[i - 1]
            temp = max(0, temp)
            ans = max(ans, temp)
        return ans


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().maxProfit(data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [7, 1, 5, 3, 6, 4]
        expect = 5
        self.run_test(data, expect)

    def test_case2(self):
        data = [7, 6, 4, 3, 1]
        expect = 0
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
