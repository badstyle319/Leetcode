import unittest
from typing import Optional

from common import TreeNode, create_binary_tree


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return 0 if not root else max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

    def maxDepthIterative(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        from collections import deque

        dq = deque([root])
        node_count, levels = 1, 0
        while dq:
            node = dq.popleft()
            if node.left:
                dq.append(node.left)
            if node.right:
                dq.append(node.right)
            node_count -= 1
            if node_count == 0:
                levels += 1
                node_count = len(dq)

        return levels


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        # result = Solution().maxDepth(create_binary_tree(data))
        result = Solution().maxDepthIterative(create_binary_tree(data))

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [3, 9, 20, None, None, 15, 7]
        expect = 3
        self.run_test(data, expect)

    def test_case2(self):
        data = [1, None, 2]
        expect = 2
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
