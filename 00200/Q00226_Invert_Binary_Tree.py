import unittest
from typing import Optional

from common import TreeNode, create_binary_tree, dump_binary_Tree


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().invertTree(create_binary_tree(data))

        self.assertEqual(dump_binary_Tree(result), expect)

    def test_case1(self):
        data = [4, 2, 7, 1, 3, 6, 9]
        expect = [4, 7, 2, 9, 6, 3, 1]
        self.run_test(data, expect)

    def test_case2(self):
        data = [2, 1, 3]
        expect = [2, 3, 1]
        self.run_test(data, expect)

    def test_case3(self):
        data = []
        expect = []
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
