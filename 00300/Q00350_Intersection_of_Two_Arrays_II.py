import unittest
from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {}
        ans = []
        for num in nums1:
            if num not in mp:
                mp[num] = 0
            mp[num] += 1
        for num in nums2:
            if num in mp and mp[num] > 0:
                ans.append(num)
                mp[num] -= 1
        return ans


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().intersect(**data)

        self.assertCountEqual(result, expect)

    def test_case1(self):
        data = {'nums1': [1, 2, 2, 1], 'nums2': [2, 2]}
        expect = [2, 2]
        self.run_test(data, expect)

    def test_case2(self):
        data = {'nums1': [4, 9, 5], 'nums2': [9, 4, 9, 8, 4]}
        expect = [4, 9]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
