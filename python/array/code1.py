A = [3, 1, 5, 9, 7, 13, 11, 19, 15]
B = [5, 9, 15, 1, 19, 7, 3, 11, 13]


def sort(nums1, nums2, l, r):
    if l >= r:
        return
    j = l
    pivot = nums2[l]
    for i in range(l + 1, r + 1):
        if nums1[i] < pivot:
            j += 1
            nums1[i], nums1[j] = nums1[j], nums1[i]
    nums1[l], nums1[j] = nums1[j], nums1[l]
    # pre_j = j
    # 第二部分
    # pivot = nums1[j]
    j = l
    for i in range(l + 1, r + 1):
        if nums2[i] < pivot:
            j += 1
            nums2[i], nums2[j] = nums2[j], nums2[i]
    nums2[l], nums2[j] = nums2[j], nums2[l]
    sort(nums1, nums2, l, j - 1)
    sort(nums1, nums2, j + 1, r)


sort(A, B, 0, len(A) - 1)
print(A)
print(B)
