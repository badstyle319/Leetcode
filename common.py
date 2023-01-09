class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def create_linked_list(data):
    if not data:
        return None

    head = ListNode(data[0])
    cur = head
    for val in data[1:]:
        cur.next = ListNode(val)
        cur = cur.next

    return head


def dump_linked_list(head):
    ret = []
    while head:
        ret.append(head.val)
        head = head.next
    return ret
