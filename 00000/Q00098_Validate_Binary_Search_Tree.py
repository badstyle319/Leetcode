import unittest
from typing import Optional

from common import TreeNode, create_binary_tree


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def helper(node, lower, upper):
            if not node:
                return True
            if node.val <= lower or node.val >= upper:
                return False
            return helper(node.left, lower, node.val) and helper(node.right, node.val, upper)

        return helper(root, float('-inf'), float('inf'))


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().isValidBST(create_binary_tree(data))

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [2, 1, 3]
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = [5, 1, 4, None, None, 3, 6]
        expect = False
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
