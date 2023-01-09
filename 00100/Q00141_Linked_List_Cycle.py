import unittest
from typing import Optional
from common import ListNode, create_linked_list


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False

        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True

        return False


class TestResult(unittest.TestCase):
    def make_cycle(self, head, pos):
        i, tail = 0, head
        while tail.next:
            tail = tail.next

        cur = head
        while cur:
            if i == pos:
                tail.next = cur
                break
            cur = cur.next
            i += 1

    def run_test(self, data, expect):
        head = create_linked_list(data['head'])
        self.make_cycle(head, data['pos'])
        result = Solution().hasCycle(head)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {'head': [3, 2, 0, -4], 'pos': 1}
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = {'head': [1, 2], 'pos': 0}
        expect = True
        self.run_test(data, expect)

    def test_case3(self):
        data = {'head': [1], 'pos': -1}
        expect = False
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
