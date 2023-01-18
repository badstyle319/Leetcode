import unittest
from typing import Optional

from common import TreeNode, create_binary_tree, dump_binary_Tree


class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)

        if root.val > val:
            root.left = self.insertIntoBST(root.left, val)
        else:
            root.right = self.insertIntoBST(root.right, val)

        return root


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().insertIntoBST(create_binary_tree(data['root']), data['val'])

        self.assertEqual(dump_binary_Tree(result), expect)

    def test_case1(self):
        data = {'root': [4, 2, 7, 1, 3], 'val': 5}
        expect = [4, 2, 7, 1, 3, 5]
        self.run_test(data, expect)

    def test_case2(self):
        data = {'root': [40, 20, 60, 10, 30, 50, 70], 'val': 25}
        expect = [40, 20, 60, 10, 30, 50, 70, None, None, 25]
        self.run_test(data, expect)

    def test_case3(self):
        data = {'root': [4, 2, 7, 1, 3, None, None, None, None, None, None], 'val': 5}
        expect = [4, 2, 7, 1, 3, 5]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
