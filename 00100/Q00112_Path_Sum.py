import unittest
from typing import Optional

from common import TreeNode, create_binary_tree


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        return (not root.left and not root.right and root.val == targetSum) \
            or self.hasPathSum(root.left, targetSum - root.val) or \
            self.hasPathSum(root.right, targetSum - root.val)


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().hasPathSum(create_binary_tree(data['root']), data['targetSum'])

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {'root': [5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1],
                'targetSum': 22}
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = {'root': [1, 2, 3], 'targetSum': 5}
        expect = False
        self.run_test(data, expect)

    def test_case3(self):
        data = {'root': [], 'targetSum': 0}
        expect = False
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
