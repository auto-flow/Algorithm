def removeNthFromEnd(self, head, n):
    # write code here
    if head == None:
        return
    else:
        l = 0
        p = head  # 保存下来
        p_head = head
        # length
        while p:
            l += 1
            p = p.next
        tag = l - n + 1
        print(tag)
        if l == 1 and n == 1:
            return None
        count = 0
        pre = ListNode(0)
        pre.next = p_head
        while p_head:
            count += 1
            if count == tag:
                pre.next = p_head.next
                break
            pre = p_head
            p_head = p_head.next
        return head
