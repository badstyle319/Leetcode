import unittest
from typing import List


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0
        else:
            return haystack.find(needle)


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().strStr(**data)
        self.assertEqual(result, expect)

    def test_case1(self):
        data = {'haystack': 'hello', 'needle': 'll'}
        expect = 2
        self.run_test(data, expect)

    def test_case2(self):
        data = {'haystack': 'aaaaa', 'needle': 'bba'}
        expect = -1
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
