import unittest
from typing import Optional

from common import TreeNode, create_binary_tree


class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        vals = set()

        def helper(node):
            if not node:
                return False

            if node.val in vals:
                return True

            vals.add(k - node.val)
            return helper(node.left) or helper(node.right)

        return helper(root)


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().findTarget(create_binary_tree(data['root']), data['k'])

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {'root': [5, 3, 6, 2, 4, None, 7], 'k': 9}
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = {'root': [5, 3, 6, 2, 4, None, 7], 'k': 28}
        expect = False
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
