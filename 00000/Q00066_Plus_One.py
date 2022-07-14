from typing import List
from unittest import TestCase


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return list(map(int, str(int(''.join(map(str, digits))) + 1)))


class TestResult(TestCase):
    def run_test(self, data, expect):
        result = Solution().plusOne(data)
        self.assertEqual(result, expect)

    def test_case1(self):
        data = [1, 2, 3]
        expect = [1, 2, 4]
        self.run_test(data, expect)

    def test_case2(self):
        data = [4, 3, 2, 1]
        expect = [4, 3, 2, 2]
        self.run_test(data, expect)

    def test_case3(self):
        data = [9]
        expect = [1, 0]
        self.run_test(data, expect)
