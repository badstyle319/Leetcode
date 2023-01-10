import unittest
from typing import Optional

from common import ListNode, create_linked_list, dump_linked_list


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None

        return new_head


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().reverseList(create_linked_list(data))

        self.assertEqual(dump_linked_list(result), expect)

    def test_case1(self):
        data = [1, 2, 3, 4, 5]
        expect = [5, 4, 3, 2, 1]
        self.run_test(data, expect)

    def test_case2(self):
        data = [1, 2]
        expect = [2, 1]
        self.run_test(data, expect)

    def test_case3(self):
        data = []
        expect = []
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
