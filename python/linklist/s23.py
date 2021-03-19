from typing import List

from structure import ListNode


def merge(a: ListNode, b: ListNode):
    dummy = ListNode(0)
    dp = dummy
    while a and b:
        if a.val < b.val:
            dp.next = a
            a = a.next
        else:
            dp.next = b
            b = b.next
        dp = dp.next
    dp.next = a if a else b
    return dummy.next


def partition(lists):
    n = len(lists)
    if n == 0:
        return None
    elif n == 1:
        return lists[0]
    else:
        mid = len(lists) // 2
        return merge(partition(lists[:mid]), partition(lists[mid:]))


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        return partition(lists)


a = ListNode.fromList([1, 3, 5])
b = ListNode.fromList([2, 4])
print(merge(a, b))
