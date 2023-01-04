import unittest
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}

        for i, num in enumerate(nums):
            complement = target - num
            if complement in hashmap:
                return [i, hashmap[complement]]
            hashmap[num] = i

        return []


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().twoSum(data[0], data[1])
        self.assertCountEqual(result, expect)

    def test_case1(self):
        data = [[2, 7, 11, 15], 9]
        expect = [0, 1]
        self.run_test(data, expect)

    def test_case2(self):
        data = [[3, 2, 4], 6]
        expect = [1, 2]
        self.run_test(data, expect)

    def test_case3(self):
        data = [[3, 3], 6]
        expect = [0, 1]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
