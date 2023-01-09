import unittest
from typing import Optional

from common import ListNode, create_linked_list, dump_linked_list


class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head:
            return head

        sub_head = self.removeElements(head.next, val)
        head.next = sub_head

        return sub_head if head.val == val else head


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().removeElements(create_linked_list(data['head']), data['val'])

        self.assertEqual(dump_linked_list(result), expect)

    def test_case1(self):
        data = {'head': [1, 2, 6, 3, 4, 5, 6], 'val': 6}
        expect = [1, 2, 3, 4, 5]
        self.run_test(data, expect)

    def test_case2(self):
        data = {'head': [], 'val': 1}
        expect = []
        self.run_test(data, expect)

    def test_case3(self):
        data = {'head': [7, 7, 7, 7], 'val': 7}
        expect = []
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
