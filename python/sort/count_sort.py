import numpy as np


def count_sort(nums):
    N = len(nums)
    # 1. 得到数组的最大值和最小值，算出差值d
    max_ = nums[0]
    min_ = nums[0]
    for i in range(1, N):
        max_ = max(max_, nums[i])
        min_ = min(min_, nums[i])
    D = max_ - min_ + 1
    # 2. 创建统计数组并统计对应元素个数
    count_arr = [0] * D
    for num in nums:
        count_arr[num - min_] += 1
    # 3. 统计数组变形，后面元素等于前面元素之和
    sum_ = 0
    for i in range(D):
        sum_ += count_arr[i]
        count_arr[i] = sum_
    # 总的计数其实就是 N
    # 4. 倒序遍历原是数组，从统计数组找到正确位置，输出到结果数组
    sorted_nums = [0] * N
    for i in range(N):
        sorted_nums[count_arr[nums[i] - min_] - 1] = nums[i]
        count_arr[nums[i] - min_] -= 1
    return sorted_nums


def run():
    for i in range(50):
        li = np.random.randint(2, 99, [1000]).tolist()
        ans = count_sort(li.copy())
        assert ans == sorted(li.copy())


if __name__ == '__main__':
    run()
