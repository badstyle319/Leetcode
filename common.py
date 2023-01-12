class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


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


def create_binary_tree(data):
    if not data:
        return None

    from collections import deque

    root = TreeNode(data.pop(0))
    dq = deque([root])
    while data:
        node = dq.popleft()
        if data:
            val = data.pop(0)
            if val:
                node.left = TreeNode(val)
                dq.append(node.left)
        if data:
            val = data.pop(0)
            if val:
                node.right = TreeNode(val)
                dq.append(node.right)

    return root

