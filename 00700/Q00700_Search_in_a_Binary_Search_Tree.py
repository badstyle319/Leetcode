import unittest
from typing import Optional

from common import TreeNode, create_binary_tree, dump_binary_Tree


class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return None

        if root.val == val:
            return root
        else:
            return root if root.val == val else self.searchBST(root.left if root.val > val else root.right, val)


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().searchBST(create_binary_tree(data['root']), data['val'])

        self.assertEqual(dump_binary_Tree(result), expect)

    def test_case1(self):
        data = {'root': [4, 2, 7, 1, 3], 'val': 2}
        expect = [2, 1, 3]
        self.run_test(data, expect)

    def test_case2(self):
        data = {'root': [4, 2, 7, 1, 3], 'val': 5}
        expect = []
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
