class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next:ListNode = next

    @staticmethod
    def fromList(lst):
        head = None
        tail = None
        for item in lst:
            node = ListNode(item)
            if head is None:
                head = node
                tail = head
            else:
                tail.next = node
                tail = node
        return head

    def __str__(self):
        p = self
        res = ""
        while p is not None:
            res += f"{p.val} -> "
            p = p.next
        res += "O"
        return res

    __repr__ = __str__

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right