import unittest
from typing import List, Optional

from common import TreeNode, create_binary_tree


class Solution:
    def dfs(self, root: Optional[TreeNode], targetSum: int, ans: List[List[int]], path: List[int]):
        if not root:
            return

        path.append(root.val)
        targetSum -= root.val
        if not root.left and not root.right:
            if targetSum == 0:
                ans.append(path[:])
        else:
            self.dfs(root.left, targetSum, ans, path)
            self.dfs(root.right, targetSum, ans, path)
        path.pop()

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans, path = [], []
        self.dfs(root, targetSum, ans, path)
        return ans


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().pathSum(create_binary_tree(data['root']), data['targetSum'])

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {'root': [5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1],
                'targetSum': 22}
        expect = [[5, 4, 11, 2], [5, 8, 4, 5]]
        self.run_test(data, expect)

    def test_case2(self):
        data = {'root': [1, 2, 3], 'targetSum': 5}
        expect = []
        self.run_test(data, expect)

    def test_case3(self):
        data = {'root': [1, 2], 'targetSum': 0}
        expect = []
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
