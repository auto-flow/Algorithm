class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def build_by_mono_stack(nums):
    root = Node(nums[0])
    stack = [root]
    for num in nums[1:]:
        node = Node(num)
        top = None
        while stack and num > stack[-1].val:
            top = stack.pop()
        if top is None:
            stack[-1].left = node
        else:
            top.right = node
        stack.append(node)
    return root


def preorder(root):
    if root is None: return
    print(root.val, end=", ")
    preorder(root.left)
    preorder(root.right)


case1 = [3, 1, 2, 5, 4, 6]
root = build_by_mono_stack(case1)
preorder(root)
