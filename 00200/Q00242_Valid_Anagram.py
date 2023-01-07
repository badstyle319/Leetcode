import unittest
from collections import Counter


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().isAnagram(**data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {"s": "anagram", "t": "nagaram"}
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = {"s": "rat", "t": "car"}
        expect = False
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
