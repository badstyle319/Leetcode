import unittest
from typing import Optional

from common import TreeNode, create_binary_tree


class Solution:
    def isMirror(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        if not left and not right:
            return True

        if not left or not right:
            return False

        return (left.val == right.val) and \
            self.isMirror(left.left, right.right) and \
            self.isMirror(left.right, right.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isMirror(root, root)


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().isSymmetric(create_binary_tree(data))

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [1, 2, 2, 3, 4, 4, 3]
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = [1, 2, 2, None, 3, None, 3]
        expect = False
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
