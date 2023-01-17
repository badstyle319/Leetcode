import unittest
from typing import List, Optional

from common import TreeNode, create_binary_tree


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        from collections import deque

        dq = deque([root])
        ans = []
        while dq:
            temp = []
            node_count = len(dq)
            for i in range(node_count):
                node = dq.popleft()
                temp.append(node.val)
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
            ans.append(temp)

        return ans


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().levelOrder(create_binary_tree(data))

        self.assertEqual(result, expect)

    def test_case1(self):
        data = [3, 9, 20, None, None, 15, 7]
        expect = [[3], [9, 20], [15, 7]]
        self.run_test(data, expect)

    def test_case2(self):
        data = [1]
        expect = [[1]]
        self.run_test(data, expect)

    def test_case3(self):
        data = []
        expect = []
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
