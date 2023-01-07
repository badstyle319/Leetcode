import unittest
from collections import Counter


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        src, dst = Counter(magazine), Counter(ransomNote)

        for k, v in dst.items():
            if k not in src or dst[k] > src[k]:
                return False

        return True


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().canConstruct(**data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {"ransomNote": "a", "magazine": "b"}
        expect = False
        self.run_test(data, expect)

    def test_case2(self):
        data = {"ransomNote": "aa", "magazine": "ab"}
        expect = False
        self.run_test(data, expect)

    def test_case3(self):
        data = {"ransomNote": "aa", "magazine": "aab"}
        expect = True
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
