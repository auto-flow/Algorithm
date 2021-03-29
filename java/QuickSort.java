import java.util.Arrays;

public class QuickSort {
    static void quick_sort(int[] nums, int l, int r) {
        if (l >= r) return;
        int pivot = nums[l];
        int j = l;
        int tmp;
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] < pivot) {
                j++;
                tmp = nums[i]; // i j 交换
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        tmp = nums[l]; // l j 交换
        nums[l] = nums[j];
        nums[j] = tmp;
        quick_sort(nums, l, j - 1);
        quick_sort(nums, j + 1, r);
    }

    public static void main(String[] args) {
        int[] nums = {2, 6, 7, 1, 9, 8, 5, 4};
        QuickSort.quick_sort(nums, 0, nums.length - 1);
        System.out.println(Arrays.toString(nums));
    }
}
