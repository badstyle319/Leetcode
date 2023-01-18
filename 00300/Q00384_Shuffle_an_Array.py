import random
import unittest
from typing import List


class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums

    def reset(self) -> List[int]:
        return self.nums

    def shuffle(self) -> List[int]:
        return random.sample(self.nums, len(self.nums))


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        obj = Solution(data['val'][0][0])
        for i, cmd in enumerate(data['op'][1:]):
            func = getattr(obj, cmd)
            result = func()
            self.assertCountEqual(result, expect[1:][i])

    def test_case1(self):
        data = {'op': ['Solution', 'shuffle', 'reset', 'shuffle'],
                'val': [[[1, 2, 3]], [], [], []]}
        expect = [None, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
