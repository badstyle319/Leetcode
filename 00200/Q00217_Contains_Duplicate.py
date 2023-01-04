import unittest
from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        my_set = set()

        for num in nums:
            if num in my_set:
                return True
            my_set.add(num)

        return False


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().containsDuplicate(data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [1, 2, 3, 1]
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = [1, 2, 3, 4]
        expect = False
        self.run_test(data, expect)

    def test_case3(self):
        data = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
        expect = True
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
