import unittest
from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ret = ''
        for item in zip(*strs):
            if all(item[0] == x for x in item[1:]):
                ret += item[0]
            else:
                break
        return ret


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().longestCommonPrefix(data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = ['flower', 'flow', 'flight']
        expect = 'fl'
        self.run_test(data, expect)

    def test_case2(self):
        data = ['dog', 'racecar', 'car']
        expect = ''
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
