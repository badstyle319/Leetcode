import unittest

from common import TreeNode, create_binary_tree


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        node = root
        while node:
            if p.val > node.val and q.val > node.val:
                node = node.right
            elif p.val < node.val and q.val < node.val:
                node = node.left
            else:
                return node
        return root


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().lowestCommonAncestor(create_binary_tree(data['root']), TreeNode(data['p']), TreeNode(data['q']))

        self.assertEqual(result.val, expect)

    def test_case1(self):
        data = {'root': [6, 2, 8, 0, 4, 7, 9, None, None, 3, 5], 'p': 2, 'q': 8}
        expect = 6
        self.run_test(data, expect)

    def test_case2(self):
        data = {'root': [6, 2, 8, 0, 4, 7, 9, None, None, 3, 5], 'p': 2, 'q': 4}
        expect = 2
        self.run_test(data, expect)

    def test_case3(self):
        data = {'root': [2, 1], 'p': 2, 'q': 1}
        expect = 2
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
