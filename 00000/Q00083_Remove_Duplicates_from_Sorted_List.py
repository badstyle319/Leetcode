import unittest
from typing import Optional

from common import ListNode, create_linked_list, dump_linked_list


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head

        while cur:
            if cur.next and cur.next.val == cur.val:
                cur.next = cur.next.next
            else:
                cur = cur.next

        return head


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().deleteDuplicates(create_linked_list(data))

        self.assertEqual(dump_linked_list(result), expect)

    def test_case1(self):
        data = [1, 1, 2]
        expect = [1, 2]
        self.run_test(data, expect)

    def test_case2(self):
        data = [1, 1, 2, 3, 3]
        expect = [1, 2, 3]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
