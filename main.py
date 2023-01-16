import unittest
from typing import List, Optional


class Solution:
    pass


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        # TODO: call function to get result
        result = Solution()

        self.assertEqual(result, expect)

    def test_case1(self):
        data = []
        expect = []
        self.run_test(data, expect)

    def test_case2(self):
        data = []
        expect = []
        self.run_test(data, expect)

    def test_case3(self):
        data = []
        expect = []
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
