import unittest
from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        a, b, pos = m - 1, n - 1, m + n - 1

        while b >= 0:
            if a >= 0 and nums1[a] > nums2[b]:
                nums1[pos] = nums1[a]
                a -= 1
            else:
                nums1[pos] = nums2[b]
                b -= 1
            pos -= 1


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        Solution().merge(**data)

        self.assertEqual(data['nums1'], expect)

    def test_case1(self):
        data = {'nums1': [1, 2, 3, 0, 0, 0], 'm': 3, 'nums2': [2, 5, 6], 'n': 3}
        expect = [1, 2, 2, 3, 5, 6]
        self.run_test(data, expect)

    def test_case2(self):
        data = {'nums1': [1], 'm': 1, 'nums2': [], 'n': 0}
        expect = [1]
        self.run_test(data, expect)

    def test_case3(self):
        data = {'nums1': [0], 'm': 0, 'nums2': [1], 'n': 1}
        expect = [1]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
