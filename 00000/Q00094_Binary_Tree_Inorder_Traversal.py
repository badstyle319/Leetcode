import unittest
from typing import List, Optional

from common import TreeNode, create_binary_tree


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return [] if not root else self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)

    def inorderTraversalIterative(self, root: Optional[TreeNode]) -> List[int]:
        res, stack = [], [(root, False)]
        while stack:
            node, visited = stack.pop()
            if node:
                if visited:
                    res.append(node.val)
                else:
                    stack.append((node.right, False))
                    stack.append((node, True))
                    stack.append((node.left, False))
        return res


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        # result = Solution().inorderTraversal(create_binary_tree(data))
        result = Solution().inorderTraversalIterative(create_binary_tree(data))

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [1, None, 2, 3]
        expect = [1, 3, 2]
        self.run_test(data, expect)

    def test_case2(self):
        data = []
        expect = []
        self.run_test(data, expect)

    def test_case3(self):
        data = [1]
        expect = [1]
        self.run_test(data, expect)

    def test_case4(self):
        data = [1, 4, 3, 2]
        expect = [2, 4, 1, 3]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
