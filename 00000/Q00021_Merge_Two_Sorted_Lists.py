import unittest
from typing import Optional

from common import ListNode, create_linked_list, dump_linked_list


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        cur = dummy = ListNode()

        while list1 and list2:
            if list1.val < list2.val:
                cur.next = list1
                list1, cur = list1.next, list1
            else:
                cur.next = list2
                list2, cur = list2.next, list2

        if list1 or list2:
            cur.next = list1 if list1 else list2

        return dummy.next


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().mergeTwoLists(create_linked_list(data['list1']), create_linked_list(data['list2']))

        self.assertEqual(dump_linked_list(result), expect)

    def test_case1(self):
        data = {'list1': [1, 2, 4], 'list2': [1, 3, 4]}
        expect = [1, 1, 2, 3, 4, 4]
        self.run_test(data, expect)

    def test_case2(self):
        data = {'list1': [], 'list2': []}
        expect = []
        self.run_test(data, expect)

    def test_case3(self):
        data = {'list1': [], 'list2': [0]}
        expect = [0]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
