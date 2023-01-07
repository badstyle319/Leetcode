import unittest


class Solution:
    def firstUniqChar(self, s: str) -> int:
        hash_map = {}

        for ch in s:
            hash_map[ch] = hash_map.get(ch, 0) + 1

        for i, ch in enumerate(s):
            if hash_map[ch] == 1:
                return i

        return -1


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().firstUniqChar(data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = "leetcode"
        expect = 0
        self.run_test(data, expect)

    def test_case2(self):
        data = "loveleetcode"
        expect = 2
        self.run_test(data, expect)

    def test_case3(self):
        data = "aabb"
        expect = -1
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
